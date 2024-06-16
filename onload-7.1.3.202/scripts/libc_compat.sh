#!/bin/bash
# SPDX-License-Identifier: GPL-2.0
# X-SPDX-Copyright-Text: (c) Solarflare Communications Inc

# Check if the library has the given symbol.
find_sym()
{
    local lib="$1"
    local sym="$2"
    local header="$3"

    echo -n "#define CI_LIBC_HAS_$sym " >>$header
    if nm -D "$lib" |grep -q "$sym"; then
        echo "1" >>$header
    else
        echo "0" >>$header
    fi
}

libc_path=$($CC $CFLAGS --print-file-name=libc.so.6)
header="$1"

if [ ! -f $libc_path ] ; then
    exit -1
fi

cat >"$header" <<EOF
/* This header is generated by scripts/libc_compat.sh */
EOF

for sym in __read_chk __recv_chk __recvfrom_chk __poll_chk \
           accept4 pipe2 dup3  epoll_pwait ppoll __ppoll_chk sendmmsg \
           splice fcntl64; do
    find_sym "$libc_path" "$sym" "$header"
done

{
rval=`check_library_presence pcap.h pcap`
if [ ! -z $require_optional_targets ]; then
  if [ $rval -eq 0 ]; then
      exit -2
  fi
fi
echo "#define CI_HAVE_PCAP $rval"

echo -n "#define CI_HAVE_SPLICE_RETURNS_SSIZE_T "
check_prototype fcntl.h splice \
    "ssize_t (*foo)(int, loff_t*, int, loff_t*, size_t, unsigned int)"
# libc 2.26 changes splice proto again
echo -n "#define CI_HAVE_SPLICE_RETURNS___SSIZE_T "
check_prototype fcntl.h splice \
    "__ssize_t (*foo)(int, __off64_t*, int, __off64_t*, size_t, unsigned int)"

# Some Ubuntus (1504) have timespec parameter in recvmmsg without
# "const" keyword.  We assume normal definition of recvmmsg if it is not
# present in libc.
echo -n "#define CI_HAVE_RECVMMSG_NOCONST_TIMESPEC "
check_prototype sys/socket.h recvmmsg \
    "int (*foo)(int, struct mmsghdr*, unsigned int, int,
                struct timespec*)"
echo -n "#define CI_HAVE_NET_TSTAMP "
check_header_presence linux/net_tstamp.h
} >> $header
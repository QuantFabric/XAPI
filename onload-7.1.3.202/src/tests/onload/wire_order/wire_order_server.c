/* SPDX-License-Identifier: BSD-2-Clause */
/* X-SPDX-Copyright-Text: (c) Solarflare Communications Inc */
/* Example application to demonstrate use of wire order delivery API.
 *
 * This is an echo server where it echoes back whatever is received on
 * N connections using a single dedicated reply connection.  It uses
 * onload_ordered_epoll_wait() to poll the N connections so that the
 * messages are echoed back in the order in which they were sent.
 */

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>
#include <strings.h>
#include <errno.h>
#include <assert.h>
#include <unistd.h>
#include <time.h>

#include <sys/epoll.h>

#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <netinet/tcp.h>
#include <linux/net_tstamp.h>

#include <onload/extensions.h>

#include "wire_order.h"

enum epoll_desc_type {
  EPOLL_DESC_TYPE_REPLY,
  EPOLL_DESC_TYPE_ACCEPT,
  EPOLL_DESC_TYPE_OTHER,
};


struct epoll_desc {
  int fd;
  enum epoll_desc_type type;
};

static int epoll_fd_cnt;


#define TRY(x)                                                          \
  do {                                                                  \
    int __rc = (x);                                                     \
      if( __rc < 0 ) {                                                  \
        fprintf(stderr, "ERROR: TRY(%s) failed\n", #x);                 \
        fprintf(stderr, "ERROR: at %s:%d\n", __FILE__, __LINE__);       \
        fprintf(stderr, "ERROR: rc=%d errno=%d (%s)\n",                 \
                __rc, errno, strerror(errno));                          \
        exit(1);                                                        \
      }                                                                 \
  } while( 0 )


static void usage(void)
{
  fprintf(stderr, "\nusage:\n");
  fprintf(stderr, "  wire_order_server [options]\n");
  fprintf(stderr, "\noptions:\n");
  fprintf(stderr, "  -p <port>             - port number to listen on\n");
  fprintf(stderr, "  -l <listenq size>     - Set size of listenq\n");
  fprintf(stderr, "  -m <max epoll events> - Maximum number of epoll events\n");
  fprintf(stderr, "  -o                    - Read individual packets and "
          "output per packet timestamps\n");
  exit(1);
}


static int get_wire_order_cfg(int socket, int32_t* n_socks_out,
                              uint32_t* flags_out)
{
  char cfg_data[WIRE_ORDER_CFG_LEN];

  TRY(recv(socket, &cfg_data, WIRE_ORDER_CFG_LEN, 0));
  memcpy(flags_out, &cfg_data[WIRE_ORDER_CFG_FLAGS_OFST], sizeof(*flags_out));
  memcpy(n_socks_out, &cfg_data[WIRE_ORDER_CFG_N_SOCKS_OFST],
         sizeof(*n_socks_out));

  return 0;
}


static int wire_order_server_ready(int socket)
{
  int dummy = 0;
  TRY(send(socket, &dummy, 1, 0));
  return 0;
}


static int my_bind(int socket, int port)
{
  struct sockaddr_in sockaddr;
  bzero(&sockaddr, sizeof(sockaddr));
  sockaddr.sin_family = AF_INET;
  sockaddr.sin_addr.s_addr = htonl(INADDR_ANY);
  sockaddr.sin_port = htons(port);
  return bind(socket, (struct sockaddr*)&sockaddr, sizeof(sockaddr));
}


static int my_epoll_add(int epoll_fd, int fd, enum epoll_desc_type type,
                        int epoll_event_mask)
{
  struct epoll_desc* epoll_desc;
  struct epoll_event epoll_ev;

  epoll_desc = calloc(1,sizeof(*epoll_desc));
  epoll_desc->fd = fd;
  epoll_desc->type = type;
  epoll_ev.events = epoll_event_mask;
  epoll_ev.data.ptr = epoll_desc;
  ++epoll_fd_cnt;
  return epoll_ctl(epoll_fd, EPOLL_CTL_ADD, fd, &epoll_ev);
}


static int my_epoll_del(int fd, struct epoll_desc* epoll_desc)
{
  --epoll_fd_cnt;
  free(epoll_desc);
  return close(fd);
}


static void simple_rx(int sock, int reply_sock, int bytes)
{
  /* We use 8 byte packets to contain our sequence numbers, so read 
   * an 8 byte chunk at a time until we've read as many bytes as we have 
   * been told are ready.
   *
   * Although it's not used in this example, we could read the
   * timestamp of the first ready data from ordered_events[i].ts.
   *
   * It would also be possible to get the timestamp associated with
   * each read using the standard SO_TIMESTAMPING API.
   */
  int rc;
  uint64_t data;
  int recvd = 0;

  while( recvd < bytes ) {
    TRY(rc = recv(sock, &data, 8, 0));
    recvd += rc;
    TRY(send(reply_sock, &data, 8, 0));
  }
}


static void init_address(struct sockaddr_in* host_address)
{
  bzero(host_address, sizeof(struct sockaddr_in));
  host_address->sin_family = AF_INET;
  host_address->sin_port = 0;
  host_address->sin_addr.s_addr = INADDR_ANY;
}


/* Given a packet, extract the timestamp and print it */
static void handle_time(struct msghdr* msg)
{
  struct timespec* ts = NULL;
  struct cmsghdr* cmsg;

  for( cmsg = CMSG_FIRSTHDR(msg); cmsg; cmsg = CMSG_NXTHDR(msg,cmsg) ) {
    if( cmsg->cmsg_level != SOL_SOCKET )
      continue;
    if ( cmsg->cmsg_type == SO_TIMESTAMPING )
      ts = (struct timespec*) CMSG_DATA(cmsg);
  }

  if( ts != NULL ) {
    printf("HW RX timestamp: " "%" PRIu64 ".%.9" PRIu64 "\n",
           (uint64_t)ts[2].tv_sec, (uint64_t)ts[2].tv_nsec);
  }
  else
    printf( "No HW timestamp\n" );
}


/* Example of using ONLOAD_MSG_ONEPKT to read each TCP packet individually.
   This allows the app to access the timestamps of each underlying packet. */
static void per_packet_rx(int sock, int reply_sock, int bytes)
{
  int rc;
  uint64_t data;
  int recvd = 0;
  struct msghdr msg;
  struct iovec iov;
  struct sockaddr_in host_address;
  char buffer[2048];
  char control[1024];

  while( recvd < bytes ) {
    /* recvmsg header structure */
    init_address(&host_address);
    iov.iov_base = buffer;
    iov.iov_len = 2048; /* will stop reading at packet boundary, but could 
                           reduce to number of remaining bytes */
    msg.msg_iov = &iov;
    msg.msg_iovlen = 1;
    msg.msg_name = &host_address;
    msg.msg_namelen = sizeof(struct sockaddr_in);
    msg.msg_control = control;
    msg.msg_controllen = 1024;

    TRY(rc = recvmsg(sock, &msg, ONLOAD_MSG_ONEPKT));
    assert(rc == 8); /* for this data should always see 8 bytes payload */
    recvd += rc;
    memcpy(&data, buffer, 8);

    int index = data >> 32;
    int recvd_seq = data & 0xffffffff;
    printf("Index: %5d\tSeq: %9d\t", index, recvd_seq);
    handle_time(&msg);

    TRY(send(reply_sock, &data, 8, 0));
  }
}


int main(int argc, char* argv[])
{
  int i, c;
  int cfg_port = DEFAULT_PORT;
  int cfg_listen_backlog = DEFAULT_LISTEN_BACKLOG;
  int cfg_max_events = DEFAULT_MAX_EPOLL_EVENTS;
  int cfg_onepkt = 0;
  uint32_t cfg_flags = 0;
  int32_t cfg_n_socks;
  int n_socks_ready = 0;
  int sock, reply_sock, epoll_fd;
  int one = 1;
  struct epoll_event* epoll_evs;
  struct onload_ordered_epoll_event* ordered_evs;
  struct epoll_desc* epoll_desc;

  while( (c = getopt(argc, argv, "p:l:m:o")) != -1 )
    switch( c ) {
    case 'p':
      cfg_port = atoi(optarg);
      break;
    case 'l':
      cfg_listen_backlog = atoi(optarg);
      break;
    case 'm':
      cfg_max_events = atoi(optarg);
      break;
    case 'o':
      cfg_onepkt = 1;
      break;
    case '?':
      usage();
      /* fallthrough */
    default:
      TRY(-1);
    }
  argc -= optind;
  argv += optind;
  if( argc != 0 )
    usage();

  epoll_evs = calloc(cfg_max_events, sizeof(*epoll_evs));
  ordered_evs = calloc(cfg_max_events, sizeof(*ordered_evs));

  if( ! onload_is_present() ) {
    fprintf(stderr,
            "WODA requires the use of Onload, please restart under onload\n\n");
    TRY(-1);
  }
  TRY(onload_stack_opt_set_int("EF_RX_TIMESTAMPING", 3));
  TRY(sock = socket(AF_INET, SOCK_STREAM, 0));
  TRY(setsockopt(sock, SOL_SOCKET, SO_REUSEADDR, (char*)&one,
                 sizeof(one)));
  TRY(setsockopt(sock, IPPROTO_TCP, TCP_NODELAY, (char*)&one,
                 sizeof(one)));
  TRY(my_bind(sock, cfg_port));
  TRY(listen(sock, cfg_listen_backlog));

  printf("Listening on port: %d\n", cfg_port);

  TRY(reply_sock = accept(sock, NULL, NULL));
  TRY(get_wire_order_cfg(reply_sock, &cfg_n_socks, &cfg_flags));

  TRY(epoll_fd = epoll_create(cfg_n_socks));
  TRY(my_epoll_add(epoll_fd, sock, EPOLL_DESC_TYPE_ACCEPT, EPOLLIN));

  if( cfg_flags & WIRE_ORDER_CFG_FLAGS_UDP ) {
    TRY(my_epoll_add(epoll_fd, reply_sock, EPOLL_DESC_TYPE_REPLY, EPOLLIN));
    for( i = 0; i < cfg_n_socks; i++ ) {
      TRY(sock = socket(AF_INET, SOCK_DGRAM, 0));
      TRY(my_bind(sock, cfg_port++));
      int enable = SOF_TIMESTAMPING_RX_HARDWARE |
        SOF_TIMESTAMPING_RAW_HARDWARE | SOF_TIMESTAMPING_SYS_HARDWARE;
      TRY(setsockopt(sock, SOL_SOCKET, SO_TIMESTAMPING, &enable, sizeof(int)));

      TRY(my_epoll_add(epoll_fd, sock, EPOLL_DESC_TYPE_OTHER, EPOLLIN));
    }
    TRY(wire_order_server_ready(reply_sock));
  }

  while( 1 ) {
    int n_epoll_evs;
    TRY(n_epoll_evs = onload_ordered_epoll_wait(epoll_fd, epoll_evs,
                                                ordered_evs,
                                                cfg_max_events, -1));
    for( i = 0; i < n_epoll_evs; ++i ) {
      epoll_desc = epoll_evs[i].data.ptr;
      assert(epoll_desc);
      switch( epoll_desc->type ) {
      case EPOLL_DESC_TYPE_REPLY:
        TRY(my_epoll_del(sock, epoll_desc));
        goto exit;
        break;
      case EPOLL_DESC_TYPE_ACCEPT:
        TRY(sock = accept(epoll_desc->fd, NULL, NULL));
        int enable = SOF_TIMESTAMPING_RX_HARDWARE |
          SOF_TIMESTAMPING_RAW_HARDWARE | SOF_TIMESTAMPING_SYS_HARDWARE;
        TRY(setsockopt(sock, SOL_SOCKET, SO_TIMESTAMPING, &enable,
                       sizeof(int)));
        TRY(my_epoll_add(epoll_fd, sock, EPOLL_DESC_TYPE_OTHER, EPOLLIN));
        if( ++n_socks_ready == cfg_n_socks )
          TRY(wire_order_server_ready(reply_sock));
        break;

      case EPOLL_DESC_TYPE_OTHER: {
        sock = epoll_desc->fd;
        if( ordered_evs[i].bytes == 0 ) {
          /* If we have our EPOLLIN event, but are told there are no bytes
           * available then we know that the fd is readable with something
           * other than ordered data.
           *
           * In our case we expect this only when sockets are closed from the
           * client end.
           */
          TRY(my_epoll_del(sock, epoll_desc));
          if( epoll_fd_cnt == 1 )
            goto exit;
        }
        else {
          /* ordered_evs[i].bytes contains the number of bytes that are
           * readable on this fd to ensure correct ordering. */
          if( ! cfg_onepkt )
            simple_rx(sock, reply_sock, ordered_evs[i].bytes);
          else
            per_packet_rx(sock, reply_sock, ordered_evs[i].bytes);
        }
        break;
      }

      default:
        fprintf(stderr, "error\n");
        exit(1);
      }
    }
  }

 exit:
  return 0;
}

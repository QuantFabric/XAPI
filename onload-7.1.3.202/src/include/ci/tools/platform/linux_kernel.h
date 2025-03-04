/* SPDX-License-Identifier: GPL-2.0 */
/* X-SPDX-Copyright-Text: (c) Solarflare Communications Inc */
/****************************************************************************
 * Copyright 2002-2005: Level 5 Networks Inc.
 * Copyright 2005-2008: Solarflare Communications Inc,
 *                      9501 Jeronimo Road, Suite 250,
 *                      Irvine, CA 92618, USA
 *
 * Maintained by Solarflare Communications
 *  <linux-xen-drivers@solarflare.com>
 *  <onload-dev@solarflare.com>
 *
 * This program is free software; you can redistribute it and/or modify it
 * under the terms of the GNU General Public License version 2 as published
 * by the Free Software Foundation, incorporated herein by reference.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 ****************************************************************************
 */


/*! \cidoxg_include_ci_tools_platform  */

#ifndef __CI_TOOLS_LINUX_KERNEL_H__
#define __CI_TOOLS_LINUX_KERNEL_H__

/**********************************************************************
 * Need to know the kernel version.
 */

#include <driver/linux_affinity/autocompat.h>

#ifndef LINUX_VERSION_CODE
# include <linux/version.h>
# if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,15)
#  include <linux/autoconf.h>
# endif
#endif

#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,0)
# error "Linux 2.6+ required"
#endif


#include <linux/slab.h>     /* kmalloc / kfree */
#include <linux/vmalloc.h>  /* vmalloc / vfree */
#include <linux/interrupt.h>/* in_interrupt()  */
#include <linux/in.h>
#include <linux/in6.h>
#include <linux/spinlock.h>
#include <linux/highmem.h>
#include <linux/sched.h>
#include <linux/ctype.h>
#include <linux/uio.h>
#include <asm/current.h>
#include <asm/errno.h>
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,26)
#include <asm/semaphore.h>
#else
#include <linux/semaphore.h>
#endif
#include <linux/workqueue.h>
#include <linux/user_namespace.h>

#include <ci/tools/config.h>

#define ci_in_interrupt  in_interrupt
#define ci_in_atomic     in_atomic


/**********************************************************************
 * Misc stuff.
 */

#ifdef BUG
/* Old Linux kernels have BUG() macro which "returns" from the gcc point of
 * view, breaking __attribute___((noreturn)).  So, we add for(;;) after
 * BUG().
 * The problem is present in 2.6.18 and is fixed in 2.6.24.
 * */
# define  CI_BOMB()     do { BUG(); for(;;); } while(0)
#endif

ci_inline void* __ci_alloc(size_t n)
{ return kmalloc(n, (in_interrupt() ? GFP_ATOMIC : GFP_KERNEL)); }

ci_inline void* __ci_atomic_alloc(size_t n)
{ return kmalloc(n, GFP_ATOMIC ); }

ci_inline void  __ci_free(void* p)     { return kfree(p);   }
ci_inline void* __ci_vmalloc(size_t n) { return vmalloc(n); }
ci_inline void  __ci_vfree(void* p)    { return vfree(p);   }


#if CI_MEMLEAK_DEBUG_ALLOC_TABLE
  #define ci_alloc(s)     ci_alloc_memleak_debug (s, __FILE__, __LINE__)
  #define ci_atomic_alloc(s)  ci_atomic_alloc_memleak_debug(s, __FILE__, __LINE__)
  #define ci_free         ci_free_memleak_debug
  #define ci_vmalloc(s)   ci_vmalloc_memleak_debug (s, __FILE__,__LINE__)
  #define ci_vfree        ci_vfree_memleak_debug
  #define ci_alloc_fn     ci_alloc_fn_memleak_debug
  #define ci_vmalloc_fn   ci_vmalloc_fn_memleak_debug
#else /* !CI_MEMLEAK_DEBUG_ALLOC_TABLE */
  #define ci_alloc_fn     __ci_alloc
  #define ci_vmalloc_fn   __ci_vmalloc
#endif 

#ifndef ci_alloc
  #define ci_atomic_alloc __ci_atomic_alloc
  #define ci_alloc        __ci_alloc
  #define ci_free         __ci_free
  #define ci_vmalloc      __ci_vmalloc
  #define ci_vmalloc_fn   __ci_vmalloc
  #define ci_vfree        __ci_vfree
#endif

#define ci_snprintf       snprintf
#define ci_vsnprintf      vsnprintf
#define ci_scnprintf      scnprintf
#define ci_vscnprintf     vscnprintf
#define ci_sscanf         sscanf


#define CI_LOG_FN_DEFAULT  ci_log_syslog

#ifdef EFRM_HAVE_KSTRTOL
#define ci_kstrtol        kstrtol
#else
#define ci_kstrtol        strict_strtol
#endif




typedef struct semaphore ci_semaphore_t;

ci_inline void
ci_sem_init (ci_semaphore_t *sem, int val) {
  sema_init (sem, val);
}

ci_inline void
ci_sem_down (ci_semaphore_t *sem) {
  down (sem);
}

ci_inline int
ci_sem_trydown (ci_semaphore_t *sem) {
  return down_trylock (sem);
}

ci_inline void
ci_sem_up (ci_semaphore_t *sem) {
  up (sem);
}

ci_inline int
ci_sem_get_count(ci_semaphore_t *sem) {
  /* count is atomic_t in <2.6.26 and in RT patch <=2.6.31; in new kernels
   * count is unsigned. */
#if LINUX_VERSION_CODE > KERNEL_VERSION(2,6,31) || \
	(LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,26) && !defined(CONFIG_PREEMPT_RT))
  return sem->count;
#else
  return sem->count.counter;
#endif
}

/**********************************************************************
 * spinlock implementation: used by <ci/tools/spinlock.h>
 */


#define CI_HAVE_SPINLOCKS

typedef ci_uintptr_t    			ci_lock_holder_t;
#define ci_lock_thisthread 		(ci_lock_holder_t)current		       	
#define ci_lock_no_holder     (ci_lock_holder_t)NULL

typedef spinlock_t			ci_lock_i;
typedef spinlock_t			ci_irqlock_i;
typedef unsigned long			ci_irqlock_state_t;

#define IRQLOCK_CYCLES  500000

#define ci_lock_ctor_i(l)		spin_lock_init(l)
#define ci_lock_dtor_i(l)		do{}while(0)
#define ci_lock_lock_i(l)		spin_lock(l)
#define ci_lock_trylock_i(l)		spin_trylock(l)
#define ci_lock_unlock_i(l)		spin_unlock(l)

/* We don't run any code in hard IRQ context, so only block soft interrupts
 * (bottom-halves).
 */
#define ci_irqlock_ctor_i(l)		spin_lock_init(l)
#define ci_irqlock_dtor_i(l)		do{}while(0)
#define ci_irqlock_lock_i(l,s)		\
  do {                                  \
    (void)(s);                          \
    spin_lock_bh(l);                    \
  } while(0)
#define ci_irqlock_unlock_i(l,s)	\
  do {					\
    (void)(s);                          \
    spin_unlock_bh(l);                  \
  } while(0)

/**********************************************************************
 * register access
 */

#include <asm/io.h>

#if LINUX_VERSION_CODE >= KERNEL_VERSION(2,6,9)
typedef volatile void __iomem*	ioaddr_t;
#else
typedef unsigned long ioaddr_t;
#endif



/**********************************************************************
 * thread implementation -- kernel dependancies probably should be
 * moved to driver/linux_kernel.h
 */

#define ci_linux_daemonize(name) daemonize(name)

#include <linux/workqueue.h>


typedef struct {
  void*			(*fn)(void* arg);
  void*			arg;
  const char*		name;
  struct task_struct*	thrd_id;
  struct completion	exit_event;
} ci_kernel_thread_t;


typedef ci_kernel_thread_t* cithread_t;


extern int cithread_create(cithread_t* tid, void* (*fn)(void*), void* arg,
			   const char* name);
extern int cithread_detach(cithread_t kt);
extern int cithread_join(cithread_t kt);


/* Kernel sysctl variables. */
extern int sysctl_tcp_wmem[3];
extern int sysctl_tcp_rmem[3];
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,24)
#define LINUX_HAS_SYSCTL_MEM_MAX
extern __u32 sysctl_wmem_max;
extern __u32 sysctl_rmem_max;
#endif


/*--------------------------------------------------------------------
 *
 * ci_bigbuf_t: An abstraction of a large buffer.  Needed because in the
 * Linux kernel, large buffers need to be allocated with vmalloc(), whereas
 * smaller buffers should use kmalloc().  This abstraction chooses the
 * appropriate mechansim.
 *
 *--------------------------------------------------------------------*/

typedef struct {
  char*		p;
  int		is_vmalloc;
} ci_bigbuf_t;


ci_inline int ci_bigbuf_alloc(ci_bigbuf_t* bb, size_t bytes) {
  if( bytes >= CI_PAGE_SIZE && ! ci_in_atomic() ) {
    bb->is_vmalloc = 1;
    if( (bb->p = vmalloc(bytes)) )  return 0;
  }
  bb->is_vmalloc = 0;
  bb->p = kmalloc(bytes, ci_in_interrupt() ? GFP_ATOMIC : GFP_KERNEL);
  return bb->p ? 0 : -ENOMEM;
}

ci_inline void ci_bigbuf_free(ci_bigbuf_t* bb) {
  if( bb->is_vmalloc )  vfree(bb->p);
  else                  kfree(bb->p);
}

ci_inline char* ci_bigbuf_ptr(ci_bigbuf_t* bb)
{ return bb->p; }

/**********************************************************************
 * struct iovec abstraction (for Windows port)
 */

typedef struct iovec ci_iovec;

/* Accessors for buffer/length */
#define CI_IOVEC_BASE(i) ((i)->iov_base)
#define CI_IOVEC_LEN(i)  ((i)->iov_len)

/**********************************************************************
 * UID
 */

#ifdef EFRM_HAVE_CRED_H
#include <linux/cred.h>
#endif

ci_inline uid_t ci_geteuid(void)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,27)
  return current->euid;
#elif LINUX_VERSION_CODE < KERNEL_VERSION(3,5,0)
  return current_euid();
#else
  return __kuid_val(current_euid());
#endif
}


ci_inline uid_t ci_getuid(void)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,27)
  return current->uid;
#elif LINUX_VERSION_CODE < KERNEL_VERSION(3,5,0)
  return current_uid();
#else
  return __kuid_val(current_uid());
#endif
}

ci_inline uid_t ci_getegid(void)
{
#if LINUX_VERSION_CODE < KERNEL_VERSION(2,6,27)
  return current->egid;
#elif LINUX_VERSION_CODE < KERNEL_VERSION(3,5,0)
  return current_egid();
#else
  return from_kgid(&init_user_ns, current_egid());
#endif
}

/* gid: -2 - none group, -1 - everyone group or actual gid */
ci_inline int ci_in_egroup(int gid)
{
  return gid != -2 && (gid == -1 ||
#ifndef KGIDT_INIT /* appeared in 3.5.0 */
      in_egroup_p((unsigned)gid));
#else
      in_egroup_p(KGIDT_INIT(gid)));
#endif
}


/* Although some support for user namespaces is present in earlier kernel
 * versions there's some variation in exactly what is supported, and no
 * supported distributions enable it with earlier kernels than 3.10.  We
 * can avoid having to support interim kernel versions by only
 * supporting user namespaces in more recent kernels.
 */
#if (LINUX_VERSION_CODE >= KERNEL_VERSION(3,10,0)) && defined(CONFIG_USER_NS)
#define EFRM_DO_USER_NS
#endif

ci_inline uid_t ci_current_from_kuid_munged(uid_t uid)
{
#ifdef EFRM_DO_USER_NS
  uid = from_kuid_munged(current_user_ns(), KUIDT_INIT(uid));
#endif
  return uid;
}

ci_inline uid_t ci_from_kuid_munged(struct user_namespace* ns, uid_t uid)
{
#ifdef EFRM_DO_USER_NS
  return from_kuid_munged(ns, KUIDT_INIT(uid));
#else
  return uid;
#endif
}

ci_inline uid_t ci_make_kuid(struct user_namespace*ns, uid_t uid)
{
#ifdef EFRM_DO_USER_NS
  kuid_t kuid = make_kuid(ns, uid);
  return __kuid_val(kuid);
#else
  return uid;
#endif
}

#endif  /* __CI_TOOLS_LINUX_KERNEL_H__ */
/*! \cidoxg_end */

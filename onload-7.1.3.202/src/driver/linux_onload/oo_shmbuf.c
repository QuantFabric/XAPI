#include <onload/debug.h>
#include <onload/oo_shmbuf.h>


int oo_shmbuf_alloc(struct oo_shmbuf* sh, int order, int max, int init_num)
{
  int i;

  sh->max = max;
  sh->order = order;
  sh->num = init_num;
  sh->init_num = init_num;
  mutex_init(&sh->lock);

  sh->addrs = kzalloc(sizeof(sh->addrs[0]) * max, GFP_KERNEL);
  if( sh->addrs == NULL )
    return -ENOMEM;

  sh->addrs[0] = vmalloc_user((unsigned long)init_num << PAGE_SHIFT << order);
  if( sh->addrs[0] == 0 ) {
    ci_log("%s: failed to allocate a virtually-continuous buffer of size %ld",
           __func__, (unsigned long)init_num << PAGE_SHIFT << order);
    return -ENOMEM;
  }

  for( i = 1; i < init_num; i++ )
    sh->addrs[i] = OO_SHMBUF_INIT_CHUNK;
  return 0;
}

void oo_shmbuf_free(struct oo_shmbuf* sh)
{
  int i;

  if( sh->addrs[0] )
    vfree(sh->addrs[0]);

  for( i = sh->init_num; i < sh->num && sh->addrs[i] != 0; i++ )
    vfree(sh->addrs[i]);

  kfree(sh->addrs);
}

/* Allocates a new chunk.
 *
 * Must not be called from any atomic/softirq/etc context, because it is
 * uses vmalloc().
 */
int oo_shmbuf_add(struct oo_shmbuf* sh)
{
  int i;

  mutex_lock(&sh->lock);

  i = sh->num;
  /* Fixme implement locking */

  sh->addrs[i] = vmalloc_user(PAGE_SIZE << sh->order);
  if( sh->addrs[i] == 0 ) {
    mutex_unlock(&sh->lock);
    return -ENOMEM;
  }

  sh->num++;
  mutex_unlock(&sh->lock);

  return i;
}

unsigned long __oo_shmbuf_ptr2off(const struct oo_shmbuf* sh, char* ptr)
{
  int i;
  unsigned long off;

  /* Fast path is handled at oo_shmbuf_ptr2off().
   * This function is for slow path only.
   */
  off = ptr - oo_shmbuf_idx2ptr(sh, 0);
  ci_assert(off < 0 || off >= oo_shmbuf_chunk_size(sh) * sh->init_num);

  /* We'd better never hit this path! */
  ci_assert(0);

  for(i = sh->init_num; i < sh->num; i++) {
    off = ptr - oo_shmbuf_idx2ptr(sh, i);

    if( off >= 0 && off < oo_shmbuf_chunk_size(sh) )
      return (i << sh->order << PAGE_SHIFT) + off;
  }
  ci_assert(0);
  return -1;
}

#ifdef EFRM_HAS_REMAP_VMALLOC_RANGE_PARTIAL
/* linux<5.13 */
static int
oo_remap_vmalloc_range_partial(struct vm_area_struct *vma, unsigned long uaddr,
                              void *kaddr, unsigned long size)
{
  return remap_vmalloc_range_partial(vma, uaddr, kaddr,
#ifdef EFRM_REMAP_VMALLOC_RANGE_PARTIAL_NEW
                                     0 /*pgoff, in linux>=5.7 */,
#endif
                                     size);
}
#else
/* linux>=5.13 */
static int
oo_remap_vmalloc_range_partial(struct vm_area_struct *vma, unsigned long uaddr,
                              void *kaddr, unsigned long size)
{
  unsigned long npages = size >> PAGE_SHIFT;
  struct page** pages = kmalloc_array(npages, sizeof(struct page*),
                                      GFP_KERNEL);
  unsigned long i;
  int rc;

  if( pages == NULL )
    return -ENOMEM;

  for( i = 0; i < npages; i++ ) {
    pages[i] = vmalloc_to_page(kaddr);
    ci_assert(pages[i]);
    kaddr += PAGE_SIZE;
  }

  rc = vm_insert_pages(vma, uaddr, pages, &i);

  /* There is not much we can do in case of an error. "npages - i"
   * pages have been already inserted into vma, and we can't get them out
   * of there.  So we log the error and return.
   */
  if( rc != 0 )
    ci_log("%s: partial remap for shmbuf: rc=%d, inserting %lu pages, "
           "%lu remain", __func__, rc, npages, i);

  kfree(pages);
  return rc;
}
#endif

int oo_shmbuf_fault(struct oo_shmbuf* sh, struct vm_area_struct* vma,
                    unsigned long off)
{
  int i = off >> sh->order >> PAGE_SHIFT;
  unsigned long start_off = (unsigned long)i << sh->order << PAGE_SHIFT;
  unsigned long size = oo_shmbuf_chunk_size(sh);

  ci_assert_lt(i, sh->max);
  if( sh->addrs[i] == 0 )
    return -EFAULT;

  if( i < sh->init_num ) {
    start_off = 0;
    i = 0;
    size *= sh->init_num;
  }

  return oo_remap_vmalloc_range_partial(vma, vma->vm_start + start_off,
                                        (void*)sh->addrs[i], size);
}

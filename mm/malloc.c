// SPDX-License-Identifier: BSD-3-Clause

#include <internal/mm/mem_list.h>
#include <internal/types.h>
#include <internal/essentials.h>
#include <sys/mman.h>
#include <string.h>
#include <stdlib.h>

int ok = 0;

void *malloc(size_t size)
{
  if (!ok) {
    ok = 1;
    mem_list_init();
  }
  void *r = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_ANONYMOUS | MAP_PRIVATE, -1, 0);
  if (r == MAP_FAILED)
    return NULL;
  mem_list_add(r, size);
  return r;
}

void *calloc(size_t nmemb, size_t size)
{
  return malloc(nmemb * size);
}

void free(void *ptr)
{
  struct mem_list *r = mem_list_find(ptr);
  if (r == NULL)
    return;
  munmap(r->start, r->len);
  mem_list_del(ptr);
}

void *realloc(void *ptr, size_t size)
{
  struct mem_list *r = mem_list_find(ptr);
  if (r == NULL)
    return malloc(size);
  void *n = mremap(r->start, r->len, size, 0);
  if (n == MAP_FAILED)
    return NULL;
  mem_list_del(ptr);
  mem_list_add(n, size);
  return n;
}

void *reallocarray(void *ptr, size_t nmemb, size_t size)
{
  return realloc(ptr, nmemb * size);
}

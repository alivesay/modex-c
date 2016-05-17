#ifndef H_MXMEMORY
#define H_MXMEMORY

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_log.h"
#endif

#include <stdlib.h>

void* mx_memory_malloc(const size_t size);
#define MX_MALLOC(size) mx_memory_malloc(size)
void* mx_memory_calloc(const size_t nmemb, const size_t size);
#define MX_CALLOC(nmemb, size) mx_memory_calloc(nmemb, size)
void* mx_memory_realloc(void* old_ptr, const size_t size);
#define MX_REALLOC(old_ptr, size) mx_memory_realloc(old_ptr, size)
void mx_memory_free(void* ptr);
#define MX_FREE(ptr) mx_memory_free(ptr)

#endif // H_MXMEMORY

#ifndef H_MXMEMORY
#define H_MXMEMORY

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_log.h"
#endif

#include <stdlib.h>


void* mx_memory_malloc(const size_t size);
void* mx_memory_calloc(const size_t nmemb, const size_t size);
void* mx_memory_realloc(void* oldptr, const size_t size);
void mx_memory_free(void* ptr);

#endif // H_MXMEMORY

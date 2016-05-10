#ifndef H_MXMEMORY
#define H_MXMEMORY

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_log.h"
#endif

#include <stdlib.h>

#define MX_MALLOC(ptr, size) \
    do { \
        ptr = malloc(size); \
        if (!ptr) \
            mx_log_extra(MX_LOG_CRIT, "malloc() failed", __FILE__, __func__, __LINE__); \
    }  while(0)

#define MX_CALLOC(ptr, nmemb, size) \
    do { \
        ptr = calloc(nmemb, size); \
        if (!ptr) \
            mx_log_extra(MX_LOG_CRIT, "calloc() failed", __FILE__, __func__, __LINE__); \
    } while(0)

#define MX_FREE(ptr) \
    do { \
        free(ptr); \
        ptr = NULL; \
    } while(0)

#define MX_CHECKBOUNDS(arr, n, size) ((arr != NULL) && (n >= 0) && (n < size))

void* mx_malloc(const size_t size);
void* mx_calloc(const size_t nmemb, const size_t size);
void mx_free(void* ptr);

#endif // H_MXMEMORY

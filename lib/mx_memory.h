#ifndef H_MXMEMORY
#define H_MXMEMORY

#include "mx_types.h"
#include "mx_log.h"

#include <stdlib.h>
#include <limits.h>

#define MX_MALLOC(var, size) \
    do { \
        var = malloc(size); \
        if (!var) \
        mx_log(MXLogLevel_EMERG, MX_LOG_BUILD_STR("malloc() failed")); \
    }  while(0)

#define MX_CALLOC(var, nmemb, size) \
    do { \
        var = calloc(nmemb, size); \
        if (!var) \
        mx_log(MXLogLevel_EMERG, MX_LOG_BUILD_STR("calloc() failed")); \
    } while(0)

#define MX_FREE(var) \
    do { \
        free(var); \
        var = NULL; \
    } while(0)

#define MX_CHECKBOUNDS(arr, n, size) ((arr) && (n >= 0) && (n < size))

#endif // H_MXMEMORY

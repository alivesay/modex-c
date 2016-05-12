#include "core/mx_log.h"

#include "mx_memory.h"

#include <stdlib.h>

inline void* mx_malloc(const size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        mx_log(MX_LOG_ERR, "malloc() failed");
        return NULL;
    }
    return ptr;
}

inline void* mx_calloc(const size_t nmemb, const size_t size) {
    void* ptr = calloc(nmemb, size);
    if (!ptr) {
        mx_log(MX_LOG_ERR, "calloc() failed");
        return NULL;
    }
    return ptr;
}

inline void mx_free(void* ptr) {
    free(ptr);
}

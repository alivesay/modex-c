#include "core/mx_log.h"

#include "mx_memory.h"

#include <stdlib.h>

inline void* mx_memory_malloc(const size_t size) {
    void* ptr = malloc(size);
    if (!ptr) {
        mx_log(MX_LOG_ERR, "malloc() failed");
        return NULL;
    }
    return ptr;
}

inline void* mx_memory_calloc(const size_t nmemb, const size_t size) {
    void* ptr = calloc(nmemb, size);
    if (!ptr) {
        mx_log(MX_LOG_ERR, "calloc() failed");
        return NULL;
    }
    return ptr;
}

inline void* mx_memory_realloc(void* old_ptr, const size_t size) {
    void* new_ptr = realloc(old_ptr, size);
    if (!new_ptr) {
        mx_log(MX_LOG_ERR, "ralloc() failed");
        return NULL;
    }
    return new_ptr;
}

inline void mx_memory_free(void* ptr) {
    free(ptr);
}

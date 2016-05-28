#include "core/mx_types.h"
#include "core/mx_vector.h"
#include "core/mx_memory.h"

#include "mx_uintpool.h"

mx_uintpool_t* mx_uintpool_create(void) {
    mx_uintpool_t* pool = MX_MALLOC(sizeof(mx_uintpool_t));
    mx_uintpool_init(pool);
    return pool;
}

void mx_uintpool_init(mx_uintpool_t *const pool) {
    pool->_cache = mx_vector_create();
}

void mx_uintpool_destroy(mx_uintpool_t *const pool) {
    uint64_t* cached_ref;
    for (size_t i = 0; i < pool->_cache->size; i++) {
        cached_ref = (uint64_t*)mx_vector_pop(pool->_cache);
        MX_FREE(cached_ref);
        cached_ref = NULL;
    }

    mx_vector_free(&pool->_cache);
}

void mx_uintpool_free(mx_uintpool_t** pool) {
    mx_uintpool_destroy(*pool);
    MX_FREE(*pool);
    *pool = NULL;
}

uint64_t mx_uintpool_acquire(mx_uintpool_t *const pool) {
    if (pool->_cache->size) {
        uint64_t* cached_ref = (uint64_t*)mx_vector_pop(pool->_cache);
        uint64_t value = *cached_ref;
        MX_FREE(cached_ref);
        cached_ref = NULL;
        return value;
    }

    return ++pool->_last_value;
}

void mx_uintpool_release(mx_uintpool_t *const pool, uint64_t value) {
    uint64_t* cached_ref = MX_MALLOC(sizeof(uint64_t));
    *cached_ref = value;
    mx_vector_push(pool->_cache, cached_ref);
}

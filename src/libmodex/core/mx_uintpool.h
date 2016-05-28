#ifndef H_MXUINTPOOL
#define H_MXUINTPOOL

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_vector.h"
#endif

typedef struct {
    mx_vector_t* _cache;
    uint64_t _last_value;
} mx_uintpool_t;

mx_uintpool_t* mx_uintpool_create(void);
void mx_uintpool_init(mx_uintpool_t *const pool);
void mx_uintpool_destroy(mx_uintpool_t *const pool);
void mx_uintpool_free(mx_uintpool_t** pool);
uint64_t mx_uintpool_acquire(mx_uintpool_t *const pool);
void mx_uintpool_release(mx_uintpool_t *const pool, uint64_t value);

#endif

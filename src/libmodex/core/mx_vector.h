#ifndef H_MXVECTOR
#define H_MXVECTOR

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

typedef struct {
    void **data;
    size_t capacity;
    size_t size;
} mx_vector_t;

void mx_vector_create(mx_vector_t *const vector);
void mx_vector_free(mx_vector_t* vector);
void mx_vector_grow(mx_vector_t* vector, const size_t min_capacity);
void mx_vector_append(mx_vector_t *const vector, void *const element);
void mx_vector_set(mx_vector_t *const vector, size_t index, void *const element);
void mx_vector_push(mx_vector_t *const vector, void *const element);
void* mx_vector_pop(mx_vector_t *const vector);
void* mx_vector_get(mx_vector_t *const vector, size_t index);
void mx_vector_delete(mx_vector_t *const vector, size_t index);

#endif // H_MXVECTOR

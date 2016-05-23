#include "core/mx_memory.h"
#include "core/mx_math.h"
#include "core/mx_log.h"

#include "mx_vector.h"

#include <string.h>

static const size_t _mx_vector_initial_capacity = 64;

inline void mx_vector_create(mx_vector_t *const vector) {
    vector->size = 0;
    vector->capacity = _mx_vector_initial_capacity;
    vector->data = MX_MALLOC(sizeof(void*) * vector->capacity);
}

inline void mx_vector_free(mx_vector_t* vector) {
    MX_FREE(vector->data);
}

inline void mx_vector_grow(mx_vector_t* vector, const size_t min_capacity) {
    size_t new_capacity = MX_NP2(min_capacity);
    void **data = MX_REALLOC(vector->data, sizeof(void*) * new_capacity);
    if (data) {
        vector->data = data;
        vector->capacity = new_capacity;
    }
}

inline void mx_vector_append(mx_vector_t *const vector, void *const element) {
    if (vector->capacity == vector->size) {
        mx_vector_grow(vector, vector->capacity + 1);
    }

    vector->data[vector->size++] = element;
}

inline void mx_vector_push(mx_vector_t *const vector, void *const element) {
    mx_vector_append(vector, element);
}

inline void* mx_vector_pop(mx_vector_t *const vector) {
    if (vector->size == 0)
        return NULL;

    return vector->data[--vector->size];
}

inline void mx_vector_set(mx_vector_t *const vector, size_t index, void *const element) {
    if (index >= 0 && index < vector->size) {
        vector->data[index] = element;
        return;
    }

    MX_LOG(MX_LOG_ERR, "mx_vector_set: index out of bounds");
}

inline void* mx_vector_get(mx_vector_t *const vector, size_t index) {
    if (index >=0 && index < vector->size) 
        return vector->data[index];

    MX_LOG(MX_LOG_ERR, "mx_vector_get: index out of bounds");
    return NULL;
}

inline void mx_vector_delete(mx_vector_t *const vector, size_t index) {
    if (index < 0 && index >= vector->size)
        return;

    if (index < vector->size - 1) {
        memmove(vector->data, vector->data[index + 1], vector->size - index - 1);
    }
}


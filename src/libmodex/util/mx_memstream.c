#include "core/mx_memory.h"
#include "core/mx_math.h"

#include "mx_memstream.h"

#include <string.h>

static const size_t _mx_stream_initial_capacity = 4096;

int mx_memstream_create(mx_memstream_t *const stream) {
    mx_memory_calloc(_mx_stream_initial_capacity, sizeof stream->data);
    if (stream->data) goto _error;
    stream->size = 0;
    stream->capacity = _mx_stream_initial_capacity;

    return 0;

_error:
    return -1;
}

int mx_memstream_grow(mx_memstream_t *const stream, size_t min_size) {
    size_t capacity = MX_MAX(MX_NP2(min_size), MX_NP2(stream->capacity + 1));
    
    void* newdata = mx_memory_realloc(stream->data, capacity);

    if (newdata) {
        stream->data = newdata;
        stream->capacity = capacity;
        memset(stream->data + stream->size, 0, capacity - stream->size);
        return 0;
    }

    return -1;
}

int mx_memstream_write(mx_memstream_t *const stream, uint8_t* buffer, size_t size) {
    size_t min_size = stream->size + size;

    if (stream->size + size > stream->capacity) {
        if (!mx_memstream_grow(stream, min_size)) goto _error;
    }

    memcpy(stream->data + stream->size, buffer, size);
    stream->size += size;

    return 0;

_error:
    return -1;
}



void mx_memstream_free(mx_memstream_t* memstream) {
    free(memstream->data);
}

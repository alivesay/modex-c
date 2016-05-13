#ifndef H_MXMEMSTREAM
#define H_MXMEMSTREAM

#ifndef H_MODEX
#endif

typedef struct {
    uint8_t* data;
    size_t size;
    size_t capacity;
} mx_memstream_t;

int mx_memstream_create(mx_memstream_t *const memstream);
int mx_memstream_grow(mx_memstream_t *const memstream, size_t min_size);
int mx_memstream_write(mx_memstream_t *const stream, uint8_t* buffer, size_t size);
void mx_memstream_free(mx_memstream_t* memstream);

#endif // H_MXMEMSTREAM

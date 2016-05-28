#ifndef H_MXINTMAP
#define H_MXINTMAP

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_uintpool.h"
#endif

typedef struct mx_uintmap_node_t mx_uintmap_node_t;
typedef struct mx_uintmap_node_t {
    uint64_t _key;
    void* _value;
    mx_uintmap_node_t* _prev;
    mx_uintmap_node_t* _next;

} mx_uintmap_node_t;

typedef struct {
    mx_uintmap_node_t* _head;
    mx_uintmap_node_t* _tail;
    mx_uintpool_t* _key_pool;
    uint64_t size;

} mx_uintmap_t;

mx_uintmap_t* mx_uintmap_create(void);
void mx_uintmap_init(mx_uintmap_t *const uintmap);
void mx_uintmap_destroy(mx_uintmap_t *const uintmap);
void mx_uintmap_free(mx_uintmap_t** uintmap);
uint64_t mx_uintmap_add(mx_uintmap_t *const uintmap, void* value);
void* mx_uintmap_remove(mx_uintmap_t*const uintmap, uint64_t key);
void* mx_uintmap_get(mx_uintmap_t* uintmap, uint64_t key);

#endif // H_MXINTMAP

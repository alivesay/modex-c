#include "core/mx_types.h"
#include "core/mx_memory.h"
#include "core/mx_uintpool.h"

#include "mx_uintmap.h"

mx_uintmap_t* mx_uintmap_create(void) {
    mx_uintmap_t* uintmap = MX_CALLOC(1, sizeof(mx_uintmap_t));
    mx_uintmap_init(uintmap);
    return uintmap;
}

void mx_uintmap_init(mx_uintmap_t *const uintmap) {
    uintmap->_head = MX_CALLOC(1, sizeof(mx_uintmap_node_t));
    uintmap->_tail = MX_CALLOC(1, sizeof(mx_uintmap_node_t));
    uintmap->_head->_next = uintmap->_tail;
    uintmap->_tail->_prev = uintmap->_head;
    uintmap->_key_pool = mx_uintpool_create();
}

void mx_uintmap_destroy(mx_uintmap_t *const uintmap) {
    mx_uintmap_node_t* p;

    while (p = uintmap->_head->_next) {
        MX_FREE(p);
        p = NULL;
    }

    MX_FREE(uintmap->_head);
    uintmap->_head = NULL;

    mx_uintpool_free(&uintmap->_key_pool);
}

void mx_uintmap_free(mx_uintmap_t** uintmap) {
    mx_uintmap_destroy(*uintmap);
    MX_FREE(*uintmap);
    *uintmap = NULL;
}

uint64_t mx_uintmap_add(mx_uintmap_t *const uintmap, void* value) {
    mx_uintmap_node_t* p = uintmap->_head;
    mx_uintmap_node_t* new_node;

    uint64_t key = mx_uintpool_acquire(uintmap->_key_pool);

    while (p != uintmap->_tail && p->_next->_key < key) p = p->_next;

    if (p != uintmap->_tail && p->_key == key) {
        p->_value = value;
        return key;
    }

    new_node = MX_MALLOC(sizeof(mx_uintmap_node_t));
    new_node->_key = key;
    new_node->_value = value;
    new_node->_next = p;
    new_node->_prev = p->_prev;
    p->_prev->_next = new_node;

    uintmap->size++;
    return key;
}

void* mx_uintmap_remove(mx_uintmap_t *const uintmap, uint64_t key) {
    mx_uintmap_node_t* p = uintmap->_head;
    void* value;

    while (p != uintmap->_tail && p->_key != key) p = p->_next;

    if (p != uintmap->_tail && p->_key == key) {
        value = p->_value;
        p->_next->_prev = p->_prev;
        p->_prev->_next = p->_next;
        MX_FREE(p);
        p = NULL;

        uintmap->size--;
        return value;
    }

    return NULL;
}

void* mx_uintmap_get(mx_uintmap_t* uintmap, uint64_t key) {
    mx_uintmap_node_t* p = uintmap->_head;

    while (p != uintmap->_tail && p->_key != key) p = p->_next;

    if (p != uintmap->_tail && p->_key == key)
        return p->_value;
    else
        return NULL;
}

// TODO: this needs a free custom func

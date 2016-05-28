#include "core/mx_types.h"
#include "core/mx_memory.h"

#include "mx_slist.h"

#include <stdlib.h>

mx_slist_t* mx_slist_create(void) {
    mx_slist_t* slist = MX_CALLOC(1, sizeof(mx_slist_t));
    mx_slist_init(slist);
    return slist;
}

void mx_slist_init(mx_slist_t *const slist) {
}

void mx_slist_free(mx_slist_t** slist) {
    mx_slist_t* p;
    mx_slist_t* last_node = *slist;
    
    while ((p = last_node)) {
        last_node = last_node->next;
        MX_FREE(p);
    }
    *slist = NULL;
}

void mx_slist_free_custom(mx_slist_t **slist, const mx_free_fn_t free_fn) {
    mx_slist_t* p;
    mx_slist_t* last_node = *slist;

    while (p = last_node) {
        last_node = last_node->next;
        free_fn(p->data);
        MX_FREE(p);
    }
    *slist = NULL;
}

mx_slist_t* mx_slist_insert(mx_slist_t *const slist, void *const data) {
    mx_slist_t* p;

    p = MX_MALLOC(sizeof(*p));
    if (!p) return NULL;

    p->data = data;
    p->next = slist;

    return p;
}

mx_slist_t* mx_slist_insert_end(mx_slist_t *const slist, void *const data) {
    struct mx_slist_t* p;
    struct mx_slist_t* last;

    p = MX_MALLOC(sizeof(*p));
    if (!p) return NULL;

    last = slist;

    p->data = data;
    p->next = NULL;

    if (slist) {
        while (last->next) last = last->next;
        last->next = p;

        return slist;
    }

    return p;
}

bool mx_slist_remove(mx_slist_t *slist, const void *const data) {
    mx_slist_t* p;
    mx_slist_t* prev;

    p = slist;
    prev = NULL;

    while (p && p->data != data) {
        prev = p;
        p = p->next;
    }

    if (p) {
        if (prev)
            prev->next = p->next;
        else
            slist = p->next;

        MX_FREE(p);
        return true;
    }

    return false;
}

bool mx_slist_remove_custom(mx_slist_t *slist,
                            const void *const data,
                            const mx_compare_fn_t compare_fn) {

    mx_slist_t* p;
    mx_slist_t* prev;

    p = slist;
    prev = NULL;

    while (p && compare_fn(p->data, data) != 0) {
        prev = p;
        p = p->next;
    }

    if (p) {
        if (prev)
            prev->next = p->next;
        else
            slist = p->next;

        MX_FREE(p);
        return true;
    }

    return false;
}

bool mx_slist_remove_node(mx_slist_t *slist, const mx_slist_t* node) {
    mx_slist_t* p;
    mx_slist_t* prev;

    p = slist;
    prev = NULL;

    while (p && p != node) {
        prev = p;
        p = p->next;
    }

    if (p) {
        if (prev) prev->next = p->next;
        MX_FREE(p);
        return true;
    }

    return false;
}

mx_slist_t* mx_slist_find(mx_slist_t *slist, const void *const data) {
    while (slist && slist->data != data) {
        slist = slist->next;
    }

    return slist;
}

mx_slist_t* mx_slist_find_custom(mx_slist_t* slist,
                                 const void *const data,
                                 const mx_compare_fn_t compare_fn) {

    while (slist && compare_fn(slist->data, data) != 0) {
        slist = slist->next;
    }

    return slist;
}

bool mx_slist_is_empty(const mx_slist_t *const slist) {
    return mx_slist_length(slist) == 0;
}

uint64_t mx_slist_length(const mx_slist_t *slist) {
    uint64_t length = 0;

    while (slist) {
        slist = slist->next;
        length++;
    }

    return length;
}

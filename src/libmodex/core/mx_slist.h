#ifndef H_MXSLIST
#define H_MXSLIST

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

typedef struct mx_slist_t mx_slist_t;

typedef struct mx_slist_t {
    void* data;
    mx_slist_t* next;
} mx_slist_t;

mx_slist_t* mx_slist_create(void);
void mx_slist_init(mx_slist_t *const slist);
void mx_slist_destroy(mx_slist_t *const slist);
void mx_slist_free(mx_slist_t** slist);
void mx_slist_free_custom(mx_slist_t** slist, const mx_free_fn_t free_fn);
mx_slist_t* mx_slist_insert(mx_slist_t *const slist, void *const data);
mx_slist_t* mx_slist_insert_end(mx_slist_t *const slist, void *const data);
bool mx_slist_remove(mx_slist_t* slist_t, const void *const data);
bool mx_slist_remove_custom(mx_slist_t* slist,
                            const void *const data,
                            const mx_compare_fn_t compare_fn);
bool mx_slist_remove_node(mx_slist_t* slist, mx_slist_t const* node);
mx_slist_t* mx_slist_find(mx_slist_t* slist, const void *const data);
mx_slist_t* mx_slist_find_custom(mx_slist_t* slist,
                                 const void *const data,
                                 const mx_compare_fn_t compare_fn);
bool mx_slist_is_empty(const mx_slist_t *const slist);
uint64_t mx_slist_length (const mx_slist_t* slist);

#endif // H_MXSLIST

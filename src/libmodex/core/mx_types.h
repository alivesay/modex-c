#ifndef H_MXTYPES
#define H_MXTYPES

#include <stdbool.h>
#include <stdint.h>
#include <stddef.h>

typedef bool(*mx_compare_fn_t)(const void *const a, const void *const b);
typedef void(*mx_free_fn_t)(void* data);

#endif // H_MXTYPES

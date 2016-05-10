#ifndef H_MXMATH
#define H_MXMATH

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

// TODO: create matching float funcs
int64_t mx_math_min(const int64_t a, const int64_t b);
#define MX_MIN(a,b)  mx_math_min(a,b)
int64_t mx_math_max(const int64_t a, const int64_t b);
#define MX_MAX(a,b)  mx_math_max(a,b)
uint64_t mx_math_np2(int64_t n);
uint64_t mx_math_pp2(int64_t n);
bool mx_math_isp2(const uint64_t);

#endif // H_MXMATH

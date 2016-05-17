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
uint64_t mx_math_np2(uint64_t n);
#define MX_NP2(n) mx_math_np2(n)
uint64_t mx_math_pp2(uint64_t n);
#define MX_PP2(n) mx_math_pp2(n)
bool mx_math_isp2(const uint64_t n);
#define MX_ISP2(n) mx_math_isp2(n)
bool mx_math_inrange(const uint64_t n, const uint64_t min, const uint64_t max);
#define MX_INRANGE(n, min, max) mx_math_inrange(n, min, max)

#endif // H_MXMATH

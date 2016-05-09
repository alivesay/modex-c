#ifndef H_MXMATH
#define H_MXMATH

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

// TODO: create matching float funcs
uint64_t mx_math_min(const uint64_t a, const uint64_t b);
#define MX_MIN(a,b)  mx_math_min(a,b)
uint64_t mx_math_max(const uint64_t a, const uint64_t b);
#define MX_MAX(a,b)  mx_math_max(a,b)
uint64_t mx_math_np2(uint64_t n, const bool accept_current);
uint64_t mx_math_pp2(uint64_t n, const bool accept_current);
bool mx_math_isp2(const uint64_t);

#endif // H_MXMATH

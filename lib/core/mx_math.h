#ifndef H_MXMATH
#define H_MXMATH

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

uint32_t mx_math_min(uint32_t a, uint32_t b);
uint32_t MX_MIN(uint32_t a, uint32_t b);
uint32_t mx_math_max(uint32_t a, uint32_t b);
uint32_t MX_MAX(uint32_t a, uint32_t b);
uint32_t mx_math_np2(uint32_t n, bool accept_current);
uint32_t mx_math_pp2(uint32_t n, bool accept_current);
bool mx_math_isp2(uint32_t);

#endif // H_MXMATH

#ifndef H_MXMATH
#define H_MXMATH

#include "mx_types.h"

uint32 mx_math_min(uint32 a, uint32 b);
uint32 MX_MIN(uint32 a, uint32 b);
uint32 mx_math_max(uint32 a, uint32 b);
uint32 MX_MAX(uint32 a, uint32 b);
uint32 mx_math_np2(uint32 n, bool accept_current);
uint32 mx_math_pp2(uint32 n, bool accept_current);
bool mx_math_isp2(uint32);

#endif // H_MXMATH

#include "core/mx_types.h"

#include "mx_math.h"

#include <math.h>

inline int64_t mx_math_min(const int64_t a, const int64_t b) {
    return (a > b) ? (b) : (a);
}

inline int64_t mx_math_max(const int64_t a, const int64_t b) {
    return (a < b) ? (b) : (a);
}
inline uint64_t mx_math_np2(uint64_t n) {
    uint64_t i;
   
    n = (n < 2) ? 2 : n;

    n--;
    for (i = 1; i < (sizeof n << 2) + 1; i <<= 1) {
        n |= (n >> i);
    }

    return ++n; 
}

inline uint64_t mx_math_pp2(uint64_t n) {
    int64_t i;

    n = (n < 3) ? 3 : n;

    for (i = 1; i < (sizeof n << 2) + 1; i <<= 1) {
        n |= (n >> i);
    }

    return n - (n >> 1);
}

inline bool mx_math_isp2(const uint64_t n) {
    return n && !(n & (n-1));
}

inline bool mx_math_inrange(const uint64_t n, const uint64_t min, const uint64_t max) {
    return n >= min && n <= max;
}

inline float mx_math_cos(const float x) {
    return cosf(x);
}

inline float mx_math_sin(const float x) {
    return sinf(x);
}

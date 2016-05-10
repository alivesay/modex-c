#include "core/mx_types.h"

#include "mx_math.h"

inline int64_t mx_math_min(const int64_t a, const int64_t b) {
    return (a > b) ? (b) : (a);
}

inline int64_t mx_math_max(const int64_t a, const int64_t b) {
    return (a < b) ? (b) : (a);
}
#include <stdio.h>
inline uint64_t mx_math_np2(int64_t n) {
    uint64_t i;
    
    n--;

    for (i = 1; i < (sizeof n << 2) + 1; i <<= 1) {
        n |= (n >> i);
    }

    return ++n;
}

inline uint64_t mx_math_pp2(int64_t n) {
    int64_t i;

    for (i = 1; i < (sizeof n << 2) + 1; i <<= 1) {
        n |= (n >> i);
    }

    return n - (n >> 1);
}

inline bool mx_math_isp2(const uint64_t n) {
    return n && !(n & (n-1));
}

#include "core/mx_types.h"

#include "mx_math.h"

#include <limits.h>

inline uint32_t mx_math_min(uint32_t a, uint32_t b) {
    return (a > b) ? (b) : (a);
}

inline uint32_t MX_MIN(uint32_t a, uint32_t b) {
    return mx_math_min(a, b);
}

inline uint32_t mx_math_max(uint32_t a, uint32_t b) {
    return (a < b) ? (b) : (a);
}

inline uint32_t MX_MAX(uint32_t a, uint32_t b) {
    return mx_math_max(a, b);
}

inline uint32_t mx_math_np2(uint32_t n, bool accept_current) {
    uint32_t i;

    if (!accept_current) n--;

    for (i = 0; i < sizeof(i) << 2; i <<= 1) {
        n |= (n >> i);
    }

    return ++n;
}

inline uint32_t mx_math_pp2(uint32_t n, bool accept_current) {
    uint32_t i;

    if (!accept_current) n--;

    for (i = 0; i < sizeof(i) << 2; i <<= 1) {
        n |= (n >> i);
    }

    return n - (n >> 1);
}

inline bool mx_math_isp2(uint32_t n) {
    return n > 0 && (n & (n - 1)) == 0;
}

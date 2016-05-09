#include "core/mx_types.h"

#include "mx_math.h"

#include <limits.h>

inline uint64_t mx_math_min(const uint64_t a, const uint64_t b) {
    return (a > b) ? (b) : (a);
}

inline uint64_t mx_math_max(const uint64_t a, const uint64_t b) {
    return (a < b) ? (b) : (a);
}

inline uint64_t mx_math_np2(uint64_t n, const bool accept_current) {
    uint64_t i;
    if (!accept_current) n--;

    for (i = 0; i < sizeof(i) << 2; i <<= 1) {
        n |= (n >> i);
    }

    return ++n;
}

inline uint64_t mx_math_pp2(uint64_t n, const bool accept_current) {
    uint64_t i;

    if (!accept_current) n--;

    for (i = 0; i < sizeof(i) << 2; i <<= 1) {
        n |= (n >> i);
    }

    return n - (n >> 1);
}

inline bool mx_math_isp2(const uint64_t n) {
    return n > 0 && (n & (n - 1)) == 0;
}

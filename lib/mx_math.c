#include "mx_types.h"
#include "mx_math.h"

#include <limits.h>

inline uint32 mx_math_min(uint32 a, uint32 b) {
    return (a > b) ? (b) : (a);
}

inline uint32 MX_MIN(uint32 a, uint32 b) {
    return mx_math_min(a, b);
}

inline uint32 mx_math_max(uint32 a, uint32 b) {
    return (a < b) ? (b) : (a);
}

inline uint32 MX_MAX(uint32 a, uint32 b) {
    return mx_math_max(a, b);
}

inline uint32 mx_math_np2(uint32 n, bool accept_current) {
    uint32 i;

    if (!accept_current) n--;

    for (i = 0; i < sizeof(i) << 2; i <<= 1) {
        n |= (n >> i);
    }

    return ++n;
}

inline uint32 mx_math_pp2(uint32 n, bool accept_current) {
    uint32 i;

    if (!accept_current) n--;

    for (i = 0; i < sizeof(i) << 2; i <<= 1) {
        n |= (n >> i);
    }

    return n - (n >> 1);
}

inline bool mx_math_isp2(uint32 n) {
    return n > 0 && (n & (n - 1)) == 0;
}

#ifndef H_MXCOLOR
#define H_MXCOLOR

#include "mx_types.h"


typedef union {
    uint32 packed;
    struct mx_color_argb_t {
        uint8 b;
        uint8 g;
        uint8 r;
        uint8 a;
    } argb;
} mx_color4b_t;

#endif // H_MXCOLOR

#ifndef H_MXCOLOR
#define H_MXCOLOR

#include "core/mx_types.h"

typedef union {
    uint32_t packed;
    struct mx_color_argb_t {
        uint8_t b;
        uint8_t g;
        uint8_t r;
        uint8_t a;
    } argb;
} mx_color4b_t;

#endif // H_MXCOLOR

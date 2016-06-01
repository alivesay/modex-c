#ifndef H_MXCOLOR
#define H_MXCOLOR

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

typedef union {
    uint32_t packed;
    struct mx_color_argb_s {
        uint8_t b;
        uint8_t g;
        uint8_t r;
        uint8_t a;
    } argb;
} mx_color_t;

typedef struct {
    float b;
    float g;
    float r;
    float a;
} mx_color_norm_t;

mx_color_norm_t mx_color_to_norm(const mx_color_t color);
mx_color_t mx_color_from_norm(const mx_color_norm_t color);
mx_color_t mx_color_from_argb(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b);
mx_color_norm_t mx_color_norm_from_argb(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b);
mx_color_t mx_color_from_hex(uint32_t packed_color);
mx_color_norm_t mx_color_norm_from_hex(uint32_t packed_color);




#endif // H_MXCOLOR

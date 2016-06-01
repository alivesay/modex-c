#include "core/mx_types.h"

#include "mx_color.h"

inline mx_color_norm_t mx_color_to_norm(mx_color_t color) {
    mx_color_norm_t color_norm;
    color_norm.b = color.argb.b / 255.0f;
    color_norm.g = color.argb.g / 255.0f;
    color_norm.r = color.argb.r / 255.0f;
    color_norm.a = color.argb.a / 255.0f;

    return color_norm;
}

inline mx_color_t mx_color_from_norm(mx_color_norm_t color_norm) {
    mx_color_t color;
    color.argb.b = color_norm.b * 255;
    color.argb.g = color_norm.g * 255;
    color.argb.r = color_norm.r * 255;
    color.argb.a = color_norm.a * 255;

    return color;
}

inline mx_color_t mx_color_from_argb(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b) {
    mx_color_t color;

    color.argb.b = b;
    color.argb.g = g;
    color.argb.r = r;
    color.argb.a = a;

    return color;
}

inline mx_color_norm_t mx_color_norm_from_argb(const uint8_t a, const uint8_t r, const uint8_t g, const uint8_t b) {
    return mx_color_to_norm(mx_color_from_argb(a,r,g,b));
}

inline mx_color_t mx_color_from_hex(uint32_t packed_color) {
    mx_color_t color;
    color.packed = packed_color;

    return color;
}

inline mx_color_norm_t mx_color_norm_from_hex(uint32_t packed_color) {
    mx_color_norm_t color_norm;
    // do bit twiddlin' here
    return color_norm;
}

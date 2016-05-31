#ifndef H_MXGLINFO
#define H_MXGLINFO

#ifndef H_MODEX
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#endif

typedef struct {
    int64_t max_texture_image_units;
    int64_t max_texture_size;
    int64_t max_vertex_attribs;
    const uint8_t* vendor;
    const uint8_t* version;
    const uint8_t* renderer;
    const uint8_t* extensions;
} mx_gl_info_t;

mx_gl_info_t* mx_gl_info_create(void);
mx_gl_info_t* mx_gl_info_init(mx_gl_info_t *const info);
void mx_gl_info_destroy(mx_gl_info_t *const info);
void mx_gl_info_free(mx_gl_info_t** info);

#endif // H_MXGLINFO

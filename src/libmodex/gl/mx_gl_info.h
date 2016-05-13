#ifndef H_MXGLINFO
#define H_MXGLINFO

#ifndef H_MODEX
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#endif

typedef struct {
    GLint max_texture_image_units;
    GLint max_texture_size;
    const GLubyte* vendor;
    const GLubyte* version;
    const GLubyte* renderer;
    GLubyte* extensions;
} mx_gl_info_t;

void mx_gl_info_query(mx_gl_info_t *const info);

#endif // H_MXGLINFO

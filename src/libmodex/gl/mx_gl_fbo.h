#ifndef H_MXGLFBO
#define H_MXGLFBO

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#endif

typedef struct {
    GLint gl_fbo_id;
} mx_gl_fbo_t;

void mx_gl_fbo_create(mx_gl_fbo_t *const fbo);
void mx_gl_fbo_get_current(mx_gl_fbo_t *const fbo);
void mx_gl_fbo_free(mx_gl_fbo_t* fbo);

#endif // H_MXGLFBO

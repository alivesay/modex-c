#ifndef H_MXGLFBO
#define H_MXGLFBO

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#endif

typedef struct {
    GLint gl_fbo_id;
} mx_gl_fbo_t;

mx_gl_fbo_t* mx_gl_fbo_create(void);
mx_gl_fbo_t* mx_gl_fbo_init(mx_gl_fbo_t *const fbo);
void mx_gl_fbo_destroy(mx_gl_fbo_t *const fbo);
void mx_gl_fbo_free(mx_gl_fbo_t** fbo);

void mx_gl_fbo_bind(const mx_gl_fbo_t const* fbo);
void mx_gl_fbo_unbind(const mx_gl_fbo_t const* fbo);

#endif // H_MXGLFBO

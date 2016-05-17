#include "gl/mx_gl_common.h"

#include "mx_gl_fbo.h"

void mx_gl_fbo_create(mx_gl_fbo_t *const fbo) {
    glGenFramebuffers(1, &fbo->gl_fbo_id);
}

void mx_gl_fbo_get_current(mx_gl_fbo_t *const fbo) {
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo->gl_fbo_id);
}

void mx_gl_fbo_free(mx_gl_fbo_t* fbo) {
    glDeleteFramebuffers(1, &fbo->gl_fbo_id);
}

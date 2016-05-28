#include "core/mx_memory.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"

#include "mx_gl_fbo.h"

mx_gl_fbo_t* mx_gl_fbo_create(void) {
    mx_gl_fbo_t* fbo = MX_CALLOC(1, sizeof(mx_gl_fbo_t));

    if (mx_gl_fbo_init(fbo))
        return fbo;

    mx_gl_fbo_free(&fbo);
    return NULL;
}

mx_gl_fbo_t* mx_gl_fbo_init(mx_gl_fbo_t *const fbo) {
    glGenFramebuffers(1, &fbo->gl_id);

    if (glIsFramebuffer(fbo->gl_id) == GL_FALSE) {
        MX_GL_ERRCHK(MX_LOG_ERR);
        return NULL;
    }

    return fbo;
}

void mx_gl_fbo_destroy(mx_gl_fbo_t *const fbo) {
    glDeleteFramebuffers(1, &fbo->gl_id);
}

void mx_gl_fbo_free(mx_gl_fbo_t** fbo) {
    mx_gl_fbo_destroy(*fbo);
    MX_FREE(*fbo);
    *fbo = NULL;
}


/*
void mx_gl_fbo_get_current(mx_gl_fbo_t *const fbo) {
    glGetIntegerv(GL_FRAMEBUFFER_BINDING, &fbo->gl_id);
}*/

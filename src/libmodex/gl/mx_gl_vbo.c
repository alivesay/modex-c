#include "core/mx_types.h"
#include "core/mx_log.h"
#include "core/mx_math.h"
#include "core/mx_memory.h"
#include "core/mx_uintpool.h"
#include "gl/mx_gl_common.h"

#include "mx_gl_vbo.h"

mx_gl_vbo_t* mx_gl_vbo_create(const size_t size, const GLenum usage) {
    mx_gl_vbo_t* vbo = MX_CALLOC(1, sizeof(mx_gl_vbo_t));

    if (mx_gl_vbo_init(vbo, size, usage))
        return vbo;

    mx_gl_vbo_free(&vbo);
    return NULL;
}

mx_gl_vbo_t* mx_gl_vbo_init(mx_gl_vbo_t *const vbo, const size_t size, const GLenum usage) {
    vbo->buffer = MX_CALLOC(1, MX_NP2(size));
    
    if (!vbo->buffer) {
        MX_LOG(MX_LOG_ERR, "vbo buffer allocation failed");
        return NULL;
    }

    glGenBuffers(1, &vbo->gl_vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo->gl_vbo_id);
    glBufferData(GL_ARRAY_BUFFER, size, NULL, usage);

    MX_GL_ERRCHK(MX_LOG_ERR);

    return vbo;
}

void mx_gl_vbo_destroy(mx_gl_vbo_t *const vbo) {
    MX_FREE(vbo->buffer);
    glDeleteBuffers(1, &vbo->gl_vbo_id);
}

void mx_gl_vbo_free(mx_gl_vbo_t** vbo) {
    mx_gl_vbo_destroy(*vbo);
    MX_FREE(*vbo);
    *vbo = NULL;
}

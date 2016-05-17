#include "core/mx_types.h"
#include "core/mx_math.h"
#include "core/mx_memory.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl.h"

#include "mx_gl_vbo.h"

mx_gl_vbo_t* mx_gl_vbo_create(mx_gl_vbo_t *const vbo,
                      const size_t size,
                      const GLenum usage) {

    vbo->buffer = mx_memory_malloc(MX_NP2(size));
    if (!vbo->buffer) goto _error;

    glGenBuffers(1, &vbo->gl_vbo_id);
    glBindBuffer(GL_ARRAY_BUFFER, vbo->gl_vbo_id);
    glBufferData(GL_ARRAY_BUFFER, size, NULL, usage);

    MX_GL_ERRCHK(MX_LOG_ERR);

    return vbo;

_error:
    mx_gl_vbo_free(vbo);
    return NULL;
}

void mx_gl_vbo_free(mx_gl_vbo_t *vbo) {
    mx_memory_free(vbo->buffer);
    glDeleteBuffers(1, &vbo->gl_vbo_id);
}

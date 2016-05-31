#include "core/mx_types.h"
#include "core/mx_log.h"
#include "core/mx_math.h"
#include "core/mx_memory.h"
#include "core/mx_uintpool.h"
#include "core/mx_vector.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_vertex.h"

#include "mx_gl_vbo.h"

mx_gl_vbo_t* mx_gl_vbo_create(const size_t size, const GLenum usage) {
    mx_gl_vbo_t* vbo = MX_CALLOC(1, sizeof(mx_gl_vbo_t));

    if (mx_gl_vbo_init(vbo, size, usage))
        return vbo;

    mx_gl_vbo_free(&vbo);
    return NULL;
}

mx_gl_vbo_t* mx_gl_vbo_init(mx_gl_vbo_t *const vbo, const size_t vertex_count, const GLenum usage) {
    vbo->buffer_size = MX_NP2(vertex_count * sizeof(mx_gl_vertex_t));
    vbo->usage = usage;

    vbo->buffers[0] = MX_CALLOC(1, vbo->buffer_size);
    vbo->buffers[1] = MX_CALLOC(1, vbo->buffer_size);
    
    if (!(vbo->buffers[0] && vbo->buffers[1])) {
        MX_LOG(MX_LOG_ERR, "vbo buffer allocation failed");
        return NULL;
    }

    glGenBuffers(2, vbo->gl_vbo_ids);
    glBindBuffer(GL_ARRAY_BUFFER, vbo->gl_vbo_ids[0]);
    glBufferData(GL_ARRAY_BUFFER, vbo->buffer_size, NULL, vbo->usage);

    if (glIsBuffer(vbo->gl_vbo_ids[0]) == GL_FALSE) { 
        MX_GL_ERRCHK(MX_LOG_ERR);
        return NULL;
    }

    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(GL_FLOAT), (void*)0);
    glEnableVertexAttribArray(1);
    glVertexAttribPointer(1, 4, GL_FLOAT, false, 4 * sizeof(GL_FLOAT), (void*)(sizeof(GL_FLOAT)*3));
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 3, GL_FLOAT, false, 3 * sizeof(GL_FLOAT), (void*)(sizeof(GL_FLOAT)*12));


    glBindBuffer(GL_ARRAY_BUFFER, vbo->gl_vbo_ids[1]);
    glBufferData(GL_ARRAY_BUFFER, vbo->buffer_size, NULL, vbo->usage);

    if (glIsBuffer(vbo->gl_vbo_ids[1]) == GL_FALSE) { 
        MX_GL_ERRCHK(MX_LOG_ERR);
        return NULL;
    }

//    vbo->attributes = mx_vector_create();

    return vbo;
}

void mx_gl_vbo_destroy(mx_gl_vbo_t *const vbo) {
    MX_FREE(vbo->buffers[0]);
    MX_FREE(vbo->buffers[1]);
    glDeleteBuffers(2, vbo->gl_vbo_ids);
}

void mx_gl_vbo_free(mx_gl_vbo_t** vbo) {
    mx_gl_vbo_destroy(*vbo);
    MX_FREE(*vbo);
    *vbo = NULL;
}

void mx_gl_vbo_bind(const mx_gl_vbo_t* vbo) {
    glBindBuffer(GL_ARRAY_BUFFER, vbo->gl_vbo_ids[0]);
    glBufferSubData(GL_ARRAY_BUFFER, 0, vbo->buffer_size, vbo->buffers[0]);
}

void mx_gl_vbo_unbind(const mx_gl_vbo_t* vbo) {
   glBindBuffer(GL_ARRAY_BUFFER, 0); 
}

mx_gl_vertex_attrib_t *const mx_gl_vbo_attributes_push(const mx_gl_vbo_t *const vbo, mx_gl_vertex_attrib_t *const attrib) {
//    mx_vector_push(vbo->attributes, attrib);
}

void mx_gl_vbo_attributes_clear(const mx_gl_vbo_t *const vbo) {
/*    mx_gl_vertex_attrib_t* attrib;
    while (attrib = mx_vector_pop(vbo->attributes)) {
        MX_FREE(attrib);
    }
    */
}

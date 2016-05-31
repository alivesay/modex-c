#ifndef H_MXGLVBO
#define H_MXGLVBO

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_vector.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#endif

typedef struct {
    GLuint index;
    GLint size;
    GLenum type;
    GLboolean normalized;
    GLsizei stride;
    GLvoid *pointer;

} mx_gl_vertex_attrib_t;

typedef struct {
    GLuint gl_vbo_ids[2];
    GLenum usage;
    size_t buffer_size;
    // maybe use vector?
    void* buffers[2];
    size_t current_buffer;
    mx_vector_t* attributes;
} mx_gl_vbo_t;

mx_gl_vbo_t* mx_gl_vbo_create(const size_t size, const GLenum usage);
mx_gl_vbo_t* mx_gl_vbo_init(mx_gl_vbo_t *const vbo, const size_t size, const GLenum usage);
void mx_gl_vbo_destroy(mx_gl_vbo_t *const vbo);
void mx_gl_vbo_free(mx_gl_vbo_t** vbo);

void mx_gl_vbo_bind(const mx_gl_vbo_t *const vbo);
void mx_gl_vbo_unbind(const mx_gl_vbo_t*const vbo);
mx_gl_vertex_attrib_t *const mx_gl_vbo_attributes_push(const mx_gl_vbo_t *const vbo, mx_gl_vertex_attrib_t *const attrib);
void mx_gl_vbo_attributes_clear(const mx_gl_vbo_t *const vbo);

// getbackbuf(), getfrontbuf()

// TODO: double buffer
#endif // H_MXGLVBO

#ifndef H_MXGLVBO
#define H_MXGLVBO

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#endif

typedef struct {
    GLuint gl_vbo_id;
    void* buffer;
} mx_gl_vbo_t;

mx_gl_vbo_t* mx_gl_vbo_create(const size_t size, const GLenum usage);
mx_gl_vbo_t* mx_gl_vbo_init(mx_gl_vbo_t *const vbo, const size_t size, const GLenum usage);
void mx_gl_vbo_destroy(mx_gl_vbo_t *const vbo);
void mx_gl_vbo_free(mx_gl_vbo_t** vbo);

// bind
// unbind
// TODO: double buffered vbo
//
#endif // H_MXGLVBO

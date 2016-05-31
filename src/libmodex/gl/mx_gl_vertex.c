#include "core/mx_types.h"
#include "gl/mx_gl_common.h"

#include "mx_gl_vertex.h"

inline void mx_gl_vertex_set_x(mx_gl_vertex_t *const vertex, const GLfloat x) {
    vertex->v[0] = x;
}

inline void mx_gl_vertex_set_y(mx_gl_vertex_t *const vertex, const GLfloat y) {
    vertex->v[1] = y;
}

inline void mx_gl_vertex_set_z(mx_gl_vertex_t *const vertex, const GLfloat z) {
    vertex->v[2] = z;
}

inline void mx_gl_vertex_set_xyz(mx_gl_vertex_t *const vertex, const GLfloat x, const GLfloat y, const GLfloat z) {
    vertex->v[0] = x;
    vertex->v[1] = y;
    vertex->v[2] = z;
}

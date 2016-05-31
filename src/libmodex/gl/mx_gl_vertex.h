#ifndef H_MXGLVERTEX
#define H_MXGLVERTEX

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#endif

typedef struct {
    GLfloat v[3];
    GLfloat c[4];
    GLfloat t[2];
} mx_gl_vertex_t;

void mx_gl_vertex_set_x(mx_gl_vertex_t *const vertex, const GLfloat x);
void mx_gl_vertex_set_y(mx_gl_vertex_t *const vertex, const GLfloat y);
void mx_gl_vertex_set_z(mx_gl_vertex_t *const vertex, const GLfloat z);
void mx_gl_vertex_set_xyz(mx_gl_vertex_t *const vertex, const GLfloat x, const GLfloat y, const GLfloat z);

// mx_gl_vertex_set_r/g/b/a, rgba, Color
// mx_gl_... normals
// UV
//
// maybe rename this to vbo_element?


#endif // H_MXGLVERTEX

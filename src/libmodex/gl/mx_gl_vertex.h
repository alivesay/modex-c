#ifndef H_MXGLVERTEX
#define H_MXGLVERTEX

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#endif

typedef struct {
    GLfloat v[3];
    GLfloat c[4];
    GLfloat n[3];
    GLfloat t[2];
} mx_gl_vertex_t;

#endif // H_MXGLVERTEX

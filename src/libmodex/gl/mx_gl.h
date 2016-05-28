#ifndef H_MXGL
#define H_MXGL

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#include "gl/mx_gl_program.h"
#endif


typedef struct {
    mx_gl_info_t info;
    mx_gl_program_t program;
} mx_gl_t;

void mx_gl_draw_begin(const mx_gl_t *const gl);
void mx_gl_draw_end(const mx_gl_t *const gl);

void mx_gl_create(mx_gl_t *const gl);
void mx_gl_free(mx_gl_t* gl);

// set program?

#endif // H_MXGL

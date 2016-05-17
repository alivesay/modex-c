#ifndef H_MXGL
#define H_MXGL

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#include "gl/mx_gl_program.h"
#endif

#define MX_GL_ERRCHK(lvl) mx_gl_errchk(lvl, __FILE__, __func__, __LINE__)

typedef struct {
    mx_gl_info_t info;
    mx_gl_program_t program;
} mx_gl_t;

const char* mx_gl_get_errstr(const GLenum error);
void mx_gl_errchk(const mx_log_level_t level,
                  const char *const file,
                  const char *const func,
                  const int line);

void mx_gl_draw_begin(const mx_gl_t *const gl);
void mx_gl_draw_end(const mx_gl_t *const gl);

void mx_gl_create(mx_gl_t *const gl);
void mx_gl_free(mx_gl_t* gl);

// set program?

#endif // H_MXGL

#ifndef H_MXGL
#define H_MXGL

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#endif

#define MX_GL_ERRCHK(lvl) mx_gl_errchk(lvl, __FILE__, __func__, __LINE__)

typedef struct {
    mx_gl_info_t info;
} mx_gl_t;

const char* mx_gl_get_errstr(const GLenum error);
void mx_gl_errchk(const mx_log_level_t level,
                  const char *const file,
                  const char *const func,
                  const int line);

void mx_gl_init(mx_gl_t *const gl);

#endif // H_MXGL

#ifndef H_MXGLCOMMON
#define H_MXGLCOMMON

#ifndef H_MODEX
#include "core/mx_log.h"
#include "ext/glad/glad.h"
#endif

#define MX_GL_ERRCHK(lvl) mx_gl_errchk(lvl, __FILE__, __func__, __LINE__)

const char* mx_gl_get_errstr(const GLenum error);
void mx_gl_errchk(const mx_log_level_t level,
                  const char *const file,
                  const char *const func,
                  const int line);


#endif // H_MXGLCOMMON

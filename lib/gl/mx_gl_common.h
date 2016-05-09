#ifndef H_MXGLCOMMON
#define H_MXGLCOMMON

#include "../mx_types.h"

#include <epoxy/gl.h>

const char* mx_gl_get_errstr(GLenum error);
void mx_gl_errchk(char *file, int line);

#define MX_GL_ERRCHK() mx_gl_errchk(__FILE__, __LINE__)

#endif // H_MXGLCOMMON

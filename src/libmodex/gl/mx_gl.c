#include "core/mx_types.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"

#include "mx_gl.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

static const char* _mx_gl_errstr_GL_NO_ERROR =
    "GL_NO_ERROR";
static const char* _mx_gl_errstr_GL_INVALID_ENUM = 
    "GL_INVALID_ENUM";
static const char* _mx_gl_errstr_GL_INVALID_VALUE =
    "GL_INVALID_VALUE";
static const char* _mx_gl_errstr_GL_INVALID_OPERATION =
    "GL_INVALID_OPERATION";
static const char* _mx_gl_errstr_GL_INVALID_FRAMEBUFFER_OPERATION =
    "GL_INVALID_FRAMEBUFFER_OPERATION";
static const char* _mx_gl_errstr_GL_OUT_OF_MEMORY =
    "GL_OUT_OF_MEMORY";
static const char* _mx_gl_errstr_GL_UNKNOWN_ERROR =
    "GL_UNKNOWN_ERROR";

const char* mx_gl_get_errstr(const GLenum err) {
    switch (err) {
        case GL_NO_ERROR:
            return _mx_gl_errstr_GL_NO_ERROR;
        case GL_INVALID_ENUM:
            return _mx_gl_errstr_GL_INVALID_ENUM;
        case GL_INVALID_VALUE:
            return _mx_gl_errstr_GL_INVALID_VALUE;
        case GL_INVALID_OPERATION:
            return _mx_gl_errstr_GL_INVALID_OPERATION;
        case GL_INVALID_FRAMEBUFFER_OPERATION:
            return _mx_gl_errstr_GL_INVALID_FRAMEBUFFER_OPERATION;
        case GL_OUT_OF_MEMORY:
            return _mx_gl_errstr_GL_OUT_OF_MEMORY;
        default:
            return _mx_gl_errstr_GL_UNKNOWN_ERROR;
    }
}

void mx_gl_errchk(const mx_log_level_t level,
                  const char *const file,
                  const char *const func,
                  const int line) {

    GLenum err = glGetError();
    
    while (err != GL_NO_ERROR) {
        mx_log_extra(level, mx_gl_get_errstr(err), file, func, line);
        err = glGetError();
    }
}

void mx_gl_init(mx_gl_t *const gl) {
    if(!gladLoadGLES2Loader(SDL_GL_GetProcAddress)) {
        MX_LOG(MX_LOG_EMERG, "gladLoadGLES2Loader() failed");
    }
}

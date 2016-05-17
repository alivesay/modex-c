#include "core/mx_types.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#include "gl/mx_gl_fbo.h"

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

static const char *_mx_gl_default_screen_vertex_glsl =
    "#version 100\n"
    "precision highp float;\n"
    "uniform mat4 uProjectionMatrix;\n"
    "attribute vec2 Position;\n"
    "void main() {\n"
    "   gl_Position = uProjectionMatrix * vec4(Position, 0.0, 1.0);\n"
    "}";

const char *_mx_gl_default_screen_fragment_glsl =
   "#version 100\n"
   "precision highp float;\n"
    "vec4 color = vec4(1.0,1.0,1.0,1.0);\n"
    "void main() {\n"
    "   if (mod(gl_FragCoord.y, 2.0f) < 1.0) {\n"
    "       gl_FragColor = color;\n"
    "   } else {\n"
    "       gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);\n"
    "   }\n"
    "}";

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

void mx_gl_create(mx_gl_t *const gl) {
    if(!gladLoadGLES2Loader(SDL_GL_GetProcAddress)) {
        MX_LOG(MX_LOG_EMERG, "gladLoadGLES2Loader() failed");
    }

    mx_gl_info_create(&gl->info);
    mx_gl_program_create(&gl->program);
    mx_gl_program_attach_shader(&gl->program,
                                _mx_gl_default_screen_vertex_glsl,
                                GL_VERTEX_SHADER);
    mx_gl_program_attach_shader(&gl->program,
                                _mx_gl_default_screen_fragment_glsl,
                                GL_FRAGMENT_SHADER);
}

void mx_gl_free(mx_gl_t* gl) {
    mx_gl_program_free(&gl->program);
    mx_gl_info_free(&gl->info);
}

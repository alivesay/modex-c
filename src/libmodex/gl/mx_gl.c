#include "core/mx_types.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#include "gl/mx_gl_fbo.h"

#include "mx_gl.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

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

#include "core/mx_types.h"
#include "core/mx_log.h"
#include "core/mx_memory.h"
#include "core/mx_color.h"
#include "core/mx_matrix4.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#include "gl/mx_gl_fbo.h"

#include "mx_gl.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

static const _mx_clear_color = 0x204090;

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

mx_gl_t* mx_gl_create(void) {
    mx_gl_t* gl = MX_CALLOC(1, sizeof(mx_gl_t));
    if (!mx_gl_init(gl)) {
        MX_LOG(MX_LOG_CRIT, "mx_gl_create() failed");
        return NULL;
    }

    return gl;
}

mx_gl_t* mx_gl_init(mx_gl_t *const gl) {
    if(!gladLoadGLES2Loader(SDL_GL_GetProcAddress)) {
        MX_LOG(MX_LOG_EMERG, "gladLoadGLES2Loader() failed");
        return NULL;
    }

    gl->info = mx_gl_info_create();
    if (!gl->info) goto mx_error;
    
    gl->program = mx_gl_program_create();
    if (!gl->program) goto mx_error;

    mx_gl_program_attach_shader(gl->program,
                                _mx_gl_default_screen_vertex_glsl,
                                GL_VERTEX_SHADER);
    mx_gl_program_attach_shader(gl->program,
                                _mx_gl_default_screen_fragment_glsl,
                                GL_FRAGMENT_SHADER);

    gl->_ortho_view = true;
    gl->_clear_color = 

    MX_GL_ERRCHK(MX_LOG_CRIT);

    return gl;

mx_error:
    MX_LOG(MX_LOG_CRIT, "mx_gl_init() failed");
    return NULL;
}

void mx_gl_destroy(mx_gl_t* gl) {
    mx_gl_program_free(&gl->program);
    mx_gl_info_free(&gl->info);
}

void mx_gl_free(mx_gl_t** gl) {
    mx_gl_destroy(*gl);
    MX_FREE(*gl);
    *gl = NULL;
}

void mx_gl_set_projection_ortho(mx_gl_t *const gl) {
    const GLfloat z_near = -1.0f,
                  z_far = 1.0f,
                  inv_z = 1.0f / (z_far - z_near),
                  inv_y = 1.0f / (gl->_viewport[1] - gl->_viewport[3]),
                  inv_x = 1.0f / (gl->_viewport[2] - gl->_viewport[0]);

    float* matrix = gl->_proj_matrix;

    *matrix++ = 2.0f * inv_x;
    *matrix++ = 0.0f;
    *matrix++ = 0.0f;
    *matrix++ = 0.0f;

    *matrix++ = 0.0f;
    *matrix++ = 2.0f * inv_y;
    *matrix++ = 0.0f;
    *matrix++ = 0.0f;

    *matrix++ = 0.0f;
    *matrix++ = 0.0f;
    *matrix++ = -2.0f * inv_z;
    *matrix++ = 0.0f;

    *matrix++ = -(gl->_viewport[2] + gl->_viewport[0]) * inv_x;
    *matrix++ = -(gl->_viewport[1] + gl->_viewport[3]) * inv_y;
    *matrix++ = -(z_far + z_near) * inv_z;
    *matrix++ = 1.0f;
}

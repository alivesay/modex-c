#include "core/mx_types.h"
#include "core/mx_log.h"

#include "mx_gl_common.h"

#include "mx_gl_program.h"

#include <epoxy/gl.h>
#include <epoxy/glx.h>

// maybe return error?
void mx_gl_program_init(mx_gl_program_t *program) {
    program->gl_program_id = glCreateProgram();
    
    MX_GL_ERRCHK(MX_LOG_ERR);
}

void mx_gl_program_attach_shader(mx_gl_program_t *program, const char* src, GLenum type) {
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);
    glAttachShader(program->gl_program_id, shader);
    glLinkProgram(program->gl_program_id);
    glDetachShader(shader, program->gl_program_id);
    glDeleteShader(shader);

    MX_GL_ERRCHK(MX_LOG_ERR);
}

void mx_gl_program_free(mx_gl_program_t *program) {
    glDeleteProgram(program->gl_program_id);
}

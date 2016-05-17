#include "core/mx_types.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl.h"
#include "gl/mx_gl_info.h"

#include "mx_gl_program.h"

// maybe return error?
void mx_gl_program_create(mx_gl_program_t *const program) {
    program->gl_program_id = glCreateProgram();
    
    MX_GL_ERRCHK(MX_LOG_ERR);
}

void _mx_gl_program_shader_log(GLuint shader) {
    GLint log_len;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_len);
    GLchar log[log_len];
    glGetShaderInfoLog(shader, log_len, &log_len, log);
    mx_log(MX_LOG_ERR, log);
}

void mx_gl_program_attach_shader(mx_gl_program_t *const program,
                                 const char *src,
                                 const GLenum type) {
    GLuint shader = glCreateShader(type);

    glShaderSource(shader, 1, &src, NULL);
    glCompileShader(shader);

    GLuint compiled;
    glGetShaderiv(shader, GL_COMPILE_STATUS, &compiled);

    if (!compiled) {
        _mx_gl_program_shader_log(shader);
        return;
    }

    glAttachShader(program->gl_program_id, shader);
    glLinkProgram(program->gl_program_id);
    glDetachShader(shader, program->gl_program_id);
    glDeleteShader(shader);

    MX_GL_ERRCHK(MX_LOG_ERR);
}

void mx_gl_program_use(const mx_gl_program_t *const program) {
    glUseProgram(program->gl_program_id);
}

void mx_gl_program_unuse(const mx_gl_program_t *const program) {
    glUseProgram(0);
}

void mx_gl_program_free(mx_gl_program_t *program) {
    glDeleteProgram(program->gl_program_id);
}

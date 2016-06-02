#include "core/mx_types.h"
#include "core/mx_memory.h"
#include "core/mx_log.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl.h"
#include "gl/mx_gl_info.h"

#include "mx_gl_program.h"


void _mx_gl_program_attach_shader(mx_gl_program_t *const program,
                                  const char *src,
                                  const GLenum type);
void _mx_gl_program_shader_log(GLuint shader);
void _mx_gl_program_program_log(GLuint program);
void _mx_gl_program_link(mx_gl_program_t *const program);

mx_gl_program_t* mx_gl_program_create(const char *const vertex_glsl, const char *const fragment_glsl) {
    mx_gl_program_t* program = MX_CALLOC(1, sizeof(mx_gl_program_t));
    mx_gl_program_init(program, vertex_glsl, fragment_glsl);

    return program;
}

void mx_gl_program_init(mx_gl_program_t *const program, const char *const vertex_glsl, const char *const fragment_glsl) {
    program->gl_program_id = glCreateProgram();

    _mx_gl_program_attach_shader(program, vertex_glsl, GL_VERTEX_SHADER);
    _mx_gl_program_attach_shader(program, fragment_glsl, GL_FRAGMENT_SHADER);
    _mx_gl_program_link(program);

    MX_GL_ERRCHK(MX_LOG_ERR);
}

void mx_gl_program_destroy(mx_gl_program_t *const program) {
    glDeleteProgram(program->gl_program_id);
}

void mx_gl_program_free(mx_gl_program_t** program) {
    mx_gl_program_destroy(*program);
    MX_FREE(*program);
    program = NULL; 
}

void _mx_gl_program_shader_log(GLuint shader) {
    GLint log_len;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_len);
    GLchar log[log_len];
    glGetShaderInfoLog(shader, log_len, &log_len, log);
    mx_log(MX_LOG_ERR, log);
}

void _mx_gl_program_program_log(GLuint program) {
    GLint log_len;
    glGetProgramiv(program, GL_INFO_LOG_LENGTH, &log_len);
    GLchar log[log_len];
    glGetProgramInfoLog(program, log_len, &log_len, log);
    mx_log(MX_LOG_ERR, log);
}

void _mx_gl_program_attach_shader(mx_gl_program_t *const program,
                                 const char *src,
                                 const GLenum type) {
    // TODO: this is a mess
    GLuint *shader = (type == GL_VERTEX_SHADER) ?
        &program->_gl_vertex_shader_id :
        &program->_gl_fragment_shader_id;
    
    *shader = glCreateShader(type);

    glShaderSource(*shader, 1, &src, NULL);
    glCompileShader(*shader);

    GLuint compiled;
    glGetShaderiv(*shader, GL_COMPILE_STATUS, &compiled);
    if (!compiled) {
        _mx_gl_program_shader_log(*shader);
        return;
    }

    glAttachShader(program->gl_program_id, *shader);

    MX_GL_ERRCHK(MX_LOG_ERR);
}

void _mx_gl_program_link(mx_gl_program_t *const program) {
    glLinkProgram(program->gl_program_id);

    GLuint linked;
    glGetProgramiv(program->gl_program_id, GL_LINK_STATUS, &linked);
    if (!linked) {
        _mx_gl_program_program_log(program->gl_program_id);
        return;
    }

    glDetachShader(program->gl_program_id, program->_gl_vertex_shader_id);
    glDetachShader(program->gl_program_id, program->_gl_fragment_shader_id);
    glDeleteShader(program->_gl_vertex_shader_id);
    glDeleteShader(program->_gl_fragment_shader_id);

    MX_GL_ERRCHK(MX_LOG_ERR);
}

void mx_gl_program_use(const mx_gl_program_t *const program) {
    glUseProgram(program->gl_program_id);
}

void mx_gl_program_unuse(const mx_gl_program_t *const program) {
    glUseProgram(0);
}



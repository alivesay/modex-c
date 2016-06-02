#ifndef H_MXGLPROGRAM
#define H_MXGLPROGRAM

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

typedef struct {
    GLuint _gl_vertex_shader_id;
    GLuint _gl_fragment_shader_id;
    GLuint gl_program_id;
} mx_gl_program_t;

mx_gl_program_t* mx_gl_program_create(const char *const vertex_glsl, const char *const fragment_glsl);
void mx_gl_program_init(mx_gl_program_t *const program, const char *const vertex_glsl, const char *const fragment_glsl);
void mx_gl_program_destroy(mx_gl_program_t *const program);
void mx_gl_program_free(mx_gl_program_t** program);
void mx_gl_program_use(const mx_gl_program_t *const program);
void mx_gl_program_unuse(const mx_gl_program_t *const program);

#endif // H_MXGLPROGRAM

//license, 3706 ne thompson st, 503 284 8467


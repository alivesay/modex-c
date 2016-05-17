#ifndef H_MXGLPROGRAM
#define H_MXGLPROGRAM

#ifndef H_MODEX
#include "core/mx_types.h"
#endif

typedef struct {
    GLuint gl_program_id;
} mx_gl_program_t;

void mx_gl_program_create(mx_gl_program_t *const program);
void mx_gl_program_attach_shader(mx_gl_program_t *const program,
                                 const char *src,
                                 GLenum type);
void mx_gl_program_use(const mx_gl_program_t *const program);
void mx_gl_program_unuse(const mx_gl_program_t *const program);
void mx_gl_program_free(mx_gl_program_t *program);

#endif // H_MXGLPROGRAM

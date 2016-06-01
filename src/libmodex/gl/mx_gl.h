#ifndef H_MXGL
#define H_MXGL

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_color.h"
#include "core/mx_matrix4.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_info.h"
#include "gl/mx_gl_program.h"
#include "gl/mx_gl_resourcemanager.h"
#endif


typedef struct {
    mx_gl_info_t* info;
    mx_gl_program_t* program;
    mx_gl_resourcemanager_t* res_manager;
    mx_matrix4_t _proj_matrix;
    GLfloat _viewport[4];
    bool _ortho_view;
    mx_color_norm_t _clear_color;
} mx_gl_t;

// create/init/destroy/free

mx_gl_t* mx_gl_create(void);
mx_gl_t* mx_gl_init(mx_gl_t *const gl);
void mx_gl_destroy(mx_gl_t *const gl);
void mx_gl_free(mx_gl_t** gl);

void mx_gl_set_viewport(uint16_t width, uint16_t height);
void mx_gl_set_projection_ortho(mx_gl_t *const gl);

void mx_gl_draw_begin(const mx_gl_t *const gl);
void mx_gl_draw_end(const mx_gl_t *const gl);

// set program?

#endif // H_MXGL

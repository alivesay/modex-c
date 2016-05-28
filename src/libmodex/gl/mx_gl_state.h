#ifndef H_MXGLSTATE
#define H_MXGLSTATE

#ifndef H_MODEX
#include "core/mx_types.h"
#include "gl/mx_gl_program.h"
#include "gl/mx_gl_vbo.h"
#endif


typedef enum {
    MX_GL_STATE_CAP_BLEND = 1 << 0,
    MX_GL_STATE_CAP_CULL_FACE = 1 << 1,
    MX_GL_STATE_CAP_DEPTH_CLAMP = 1 << 2,
    MX_GL_STATE_CAP_DEPTH_TEST = 1 << 3
} mx_gl_state_cap_flags_t;

typedef struct {
    mx_gl_state_cap_flags_t cap_flags;
    mx_gl_program_t* program;
    mx_gl_vbo_t* vbo;

    // viewport
} mx_gl_state_t;

mx_gl_state_t* mx_gl_state_create(void);
void mx_gl_state_init(mx_gl_state_t *const state);
void mx_gl_state_destroy(mx_gl_state_t *const state);
void mx_gl_state_free(mx_gl_state_t** state);
void mx_gl_state_synchronize(mx_gl_state_t* state);
void mx_gl_state_update(mx_gl_state_t* state);
void mx_gl_state_set_capabilities(mx_gl_state_t *const state, const mx_gl_state_cap_flags_t cap_flags, const bool enabled);
void mx_gl_state_enable_capabilities(mx_gl_state_t *const state, const mx_gl_state_cap_flags_t cap_flags);
void mx_gl_state_disable_capabilities(mx_gl_state_t *const state, const mx_gl_state_cap_flags_t cap_flags);
void mx_gl_state_enable(mx_gl_state_t *const state);
void mx_gl_state_disable(mx_gl_state_t *const state);
bool mx_gl_state_compare(const mx_gl_state_t *const state_a, const mx_gl_state_t *const state_b);

#endif // H_MXGLSTATE

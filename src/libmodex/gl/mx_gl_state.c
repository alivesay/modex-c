#include "core/mx_memory.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_program.h"
#include "gl/mx_gl_vbo.h"

#include "mx_gl_state.h"

void _mx_gl_state_process_capflags(const uint32_t cap_flags, bool enable);

mx_gl_state_t* mx_gl_state_create(void) {
    mx_gl_state_t* state = MX_CALLOC(1, sizeof(mx_gl_state_t));
    mx_gl_state_init(state);

    return state;
}

void mx_gl_state_init(mx_gl_state_t *const state) {
}

void mx_gl_state_destroy(mx_gl_state_t *const state) {
}

void mx_gl_state_free(mx_gl_state_t** state) {
    mx_gl_state_destroy(*state);
    MX_FREE(*state);
    state = NULL;
}

void mx_gl_state_update(mx_gl_state_t* state) {
    // set state on all set values
}

void mx_gl_state_synchronize(mx_gl_state_t* state) {
    // set state to current values...
    // vbo refs etc will require be able to lookup vbos by GLint id
}

void mx_gl_state_enable_capabilities(mx_gl_state_t *const state, const mx_gl_state_cap_flags_t cap_flags) {
    state->cap_flags |= cap_flags;
}

void mx_gl_state_disable_capabilities(mx_gl_state_t *const state, const mx_gl_state_cap_flags_t cap_flags) {
    state->cap_flags &= ~cap_flags;
}

void _mx_gl_state_process_capflags(uint32_t cap_flags, const bool enable) {
    uint32_t cap_mask = 1;
    void (*gl_xable_fn)(GLenum) = enable ? glEnable : glDisable;

    while (cap_flags) {
        switch (cap_flags & cap_mask) {
            case MX_GL_STATE_CAP_BLEND:
                (*gl_xable_fn)(GL_BLEND);
                break;
            case MX_GL_STATE_CAP_CULL_FACE:
                (*gl_xable_fn)(GL_CULL_FACE);
                break;
//            case MX_GL_STATE_CAP_DEPTH_CLAMP:
 //               (*gl_xable_fn)(GL_DEPTH_CLAMP);
//                break;
            case MX_GL_STATE_CAP_DEPTH_TEST:
                (*gl_xable_fn)(GL_DEPTH_TEST);
                break;
        }
        cap_flags &= ~cap_mask;
        cap_mask <<= 1;
    }
}

void mx_gl_state_enable(mx_gl_state_t *const state) {
    _mx_gl_state_process_capflags(state->cap_flags, true);
    // check each flag and enable if set
    // set viewport
    // bind textures
}

void mx_gl_state_disable(mx_gl_state_t *const state) {
    _mx_gl_state_process_capflags(state->cap_flags, false);
}

bool mx_gl_state_compare(const mx_gl_state_t *const state_a, const mx_gl_state_t *const state_b) {
    bool different = true;

    different = state_a->cap_flags == state_b->cap_flags &&
                state_a->program == state_b->program &&
                state_a->vbo == state_b->vbo;

    return different;
}

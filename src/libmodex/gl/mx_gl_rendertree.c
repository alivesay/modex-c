#include "core/mx_memory.h"
#include "core/mx_vector.h"
#include "core/mx_util.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_state.h"
#include "gl/mx_gl_program.h"
#include "gl/mx_gl_vbo.h"

#include "mx_gl_rendertree.h"

#include "string.h"

void _mx_gl_rendertree_render_noop(mx_vector_t *const vector, const mx_gl_state_t *const state); 
void _mx_gl_rendertree_destroy(mx_gl_rendertree_node_t *node);
void _mx_gl_rendertree_node_create(mx_gl_rendertree_node_t *const node, const mx_gl_rendertree_node_type_t type);
void _mx_gl_rendertree_node_free(mx_gl_rendertree_node_t* node);
bool _mx_gl_rendertree_state_property_matches(void *const state_property,
                                              const mx_gl_state_t *const state,
                                              const mx_gl_rendertree_node_state_type_t state_type);
bool _mx_gl_rendertree_associate_state_node(mx_gl_rendertree_node_state_t *const state_node,
                                              const mx_gl_state_t *const state,
                                              mx_gl_rendertree_node_state_type_t state_type);


void _mx_gl_rendertree_render_noop(mx_vector_t *const vector, const mx_gl_state_t *const state) {}

mx_gl_rendertree_t* mx_gl_rendertree_create(void) {
    mx_gl_rendertree_t* tree = MX_CALLOC(1, sizeof(mx_gl_rendertree_t));
    mx_gl_rendertree_init(tree);

    return tree;
}

void mx_gl_rendertree_init(mx_gl_rendertree_t *const tree) {
    tree->root = MX_CALLOC(1, sizeof(mx_gl_rendertree_node_root_t));
    mx_gl_state_init(&tree->state);
    _mx_gl_rendertree_node_create(tree->root, MX_GL_RENDERTREE_NODE_TYPE_ROOT);
    tree->render_fn = _mx_gl_rendertree_render_noop;
}

void _mx_gl_rendertree_destroy(mx_gl_rendertree_node_t *node) {
    switch (node->type) {
        case MX_GL_RENDERTREE_NODE_TYPE_ROOT:
        case MX_GL_RENDERTREE_NODE_TYPE_STATE:
            for (size_t i = 0; i < node->children->size; i++) {
                _mx_gl_rendertree_destroy(mx_vector_get(node->children, i));
                _mx_gl_rendertree_node_free(node);
            }
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE:
            _mx_gl_rendertree_node_free(node);
            break;
    }
}

// TODO: create a resusable_free which retains state nodes and sets all object vector sizes to zero
void mx_gl_rendertree_destroy(mx_gl_rendertree_t* tree) {
    _mx_gl_rendertree_destroy(tree->root);
}

void mx_gl_rendertree_free(mx_gl_rendertree_t** tree) {
    mx_gl_rendertree_destroy(*tree);
    MX_FREE(*tree);
    *tree = NULL;
}

bool _mx_gl_rendertree_state_property_matches(void *const state_property,
                                              const mx_gl_state_t *const state,
                                              mx_gl_rendertree_node_state_type_t state_type) {

    switch (state_type) {
        case MX_GL_RENDERTREE_NODE_STATE_CAPFLAGS:
            return (*(mx_gl_state_cap_flags_t*)state_property == state->cap_flags);
//        case MX_GL_RENDERTREE_NODE_STATE_FBO:
//            break;
        case MX_GL_RENDERTREE_NODE_STATE_PROGRAM:
            return ((mx_gl_program_t*)state_property == state->program);
//        case MX_GL_RENDERTREE_NODE_STATE_TEXTURE:
//            break;
        case MX_GL_RENDERTREE_NODE_STATE_VBO:
            return ((mx_gl_vbo_t*)state_property == state->vbo);
        default:
            return false;
    }
}

bool _mx_gl_rendertree_associate_state_node(mx_gl_rendertree_node_state_t *const state_node,
                                              const mx_gl_state_t *const state,
                                              mx_gl_rendertree_node_state_type_t state_type) {

    state_node->state_type = state_type;

    switch (state_type) {
        case MX_GL_RENDERTREE_NODE_STATE_CAPFLAGS:
            state_node->state_property = (void*)&state->cap_flags; break;
//        case MX_GL_RENDERTREE_NODE_STATE_FBO:
//            break;
        case MX_GL_RENDERTREE_NODE_STATE_PROGRAM:
            state_node->state_property = (void*)state->program; break;
//        case MX_GL_RENDERTREE_NODE_STATE_TEXTURE:
//            break;
        case MX_GL_RENDERTREE_NODE_STATE_VBO:
            state_node->state_property = (void*)state->vbo; break;
        default:
            MX_LOG(MX_LOG_ERR, "unknown rendertree state association");
    }
}

void mx_gl_rendertree_add_renderable(mx_gl_rendertree_t *const tree, mx_renderable_t *const renderable) {
    // gl needs a root state, used if getstate is null
    // TODO: a lookup table cache
    // renderable_node = cache[s1,s2,s3,...]

    const mx_gl_state_t *const renderable_state = renderable->getState();

    mx_gl_rendertree_node_state_t* state_node = NULL;
    mx_gl_rendertree_node_renderable_t* renderable_node = NULL;
    mx_vector_t* children = tree->root->children;

 
    // check each known state property 
    for (uint64_t state_type = 0; state_type < _MX_GL_RENDERTREE_NODE_STATE_COUNT; state_type++) {
        for (size_t j = 0; j < children->size; j++) {
            state_node = (mx_gl_rendertree_node_state_t*)mx_vector_get(children, j);
            bool found_existing = false;
            if (state_node->state_type == state_type &&
                _mx_gl_rendertree_state_property_matches(state_node->state_property, renderable_state, state_type)) {
                    break;
            }
            state_node = NULL;
        }

        if (!state_node) {
            state_node = MX_CALLOC(1, sizeof(mx_gl_rendertree_node_state_t));
            _mx_gl_rendertree_node_create((mx_gl_rendertree_node_t*)state_node, MX_GL_RENDERTREE_NODE_TYPE_STATE);
            _mx_gl_rendertree_associate_state_node(state_node, renderable_state, state_type);
            mx_vector_append(children, state_node);
        }

        children = state_node->children;
    }

    renderable_node = MX_CALLOC(1, sizeof(mx_gl_rendertree_node_renderable_t));
    _mx_gl_rendertree_node_create((mx_gl_rendertree_node_t*)renderable_node, MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE);
    mx_vector_append(((mx_gl_rendertree_node_renderable_t*)children)->renderables, renderable);
} 

void mx_gl_rendertree_set_render_fn(mx_gl_rendertree_t *const tree, const mx_gl_rendertree_render_fn_t render_fn) {
    tree->render_fn = render_fn;
}

void mx_gl_rendertree_render(void) {
    // get each renderable/state list, callback...
    // probably shouldn't call it "Render", since it could be used for other things
    // maybe mx_gl_rendertree_stategroup...statelist... er...
}

void _mx_gl_rendertree_node_create(mx_gl_rendertree_node_t* node, const mx_gl_rendertree_node_type_t type) {
    node->type = type;

    switch (node->type) {
        case MX_GL_RENDERTREE_NODE_TYPE_ROOT:
            ((mx_gl_rendertree_node_root_t*)node)->children = mx_vector_create();
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_STATE:
            ((mx_gl_rendertree_node_state_t*)node)->children = mx_vector_create();
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE:
            ((mx_gl_rendertree_node_renderable_t*)node)->renderables = mx_vector_create();
            break;
    }
}

void _mx_gl_rendertree_node_free(mx_gl_rendertree_node_t* node) {
    switch (node->type) {
        case MX_GL_RENDERTREE_NODE_TYPE_ROOT:
            mx_vector_free(&((mx_gl_rendertree_node_root_t*)node)->children);
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_STATE:
            mx_vector_free(&((mx_gl_rendertree_node_state_t*)node)->children);
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE:
            mx_vector_free(&((mx_gl_rendertree_node_renderable_t*)node)->renderables);
            break;
    }
}

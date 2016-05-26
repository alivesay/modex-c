#include "core/mx_memory.h"
#include "core/mx_vector.h"
#include "core/mx_util.h"

#include "mx_gl_rendertree.h"

#include "string.h"

void _mx_gl_rendertree_render_noop(mx_vector_t *const vector, uint64_t state[_MX_GL_RENDERTREE_NODE_STATE_COUNT]);
void _mx_gl_rendertree_destroy(mx_gl_rendertree_node_t *node);
void _mx_gl_rendertree_node_create(mx_gl_rendertree_node_t *const node, const mx_gl_rendertree_node_type_t type);
void _mx_gl_rendertree_node_free(mx_gl_rendertree_node_t* node);

void _mx_gl_rendertree_render_noop(mx_vector_t *const vector, uint64_t state[_MX_GL_RENDERTREE_NODE_STATE_COUNT]) {}

mx_gl_rendertree_t* mx_gl_rendertree_create(void) {
    mx_gl_rendertree_t* tree = MX_CALLOC(1, sizeof(mx_gl_rendertree_t));
    mx_gl_rendertree_init(tree);

    return tree;
}

void mx_gl_rendertree_init(mx_gl_rendertree_t *const tree) {
    tree->root = MX_CALLOC(1, sizeof(mx_gl_rendertree_node_root_t));
    _mx_gl_rendertree_node_create(tree->root, MX_GL_RENDERTREE_NODE_TYPE_ROOT);
    tree->render_fn = _mx_gl_rendertree_render_noop;
}

void _mx_gl_rendertree_destroy(mx_gl_rendertree_node_t *node) {
    switch (node->type) {
        case MX_GL_RENDERTREE_NODE_TYPE_ROOT:
        case MX_GL_RENDERTREE_NODE_TYPE_STATE:
            for (size_t i = 0; i < node->children.size; i++) {
                _mx_gl_rendertree_destroy(mx_vector_get(&node->children, i));
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

void mx_gl_rendertree_add_renderable(mx_gl_rendertree_t *const tree, mx_renderable_t *const renderable) {
    // TODO: a lookup table cache
    // renderable_node = cache[s1,s2,s3,...]

    renderable->getState(tree->state);

    mx_gl_rendertree_node_state_t* state_node = NULL;
    mx_gl_rendertree_node_renderable_t* renderable_node = NULL;
    mx_vector_t* children = &tree->root->children;

    for (size_t i = 0; i < _MX_GL_RENDERTREE_NODE_STATE_COUNT; i++) {
        // find existing state at this level if it exists
        for (size_t j = 0; j < children->size; j++) {
            state_node = (mx_gl_rendertree_node_state_t*)mx_vector_get(children, j);
            if (state_node->id == tree->state[i])
                break;
            state_node = NULL;
        }

        // add it if not found
        if (!state_node) {
            state_node = MX_CALLOC(1, sizeof(mx_gl_rendertree_node_state_t));
            _mx_gl_rendertree_node_create((mx_gl_rendertree_node_t*)state_node, MX_GL_RENDERTREE_NODE_TYPE_STATE);
            mx_vector_append(children, state_node);
        }

        children = &state_node->children;
    }
    
    // TODO: do something with renderable param
    renderable_node = MX_CALLOC(1, sizeof(mx_gl_rendertree_node_renderable_t));
    _mx_gl_rendertree_node_create((mx_gl_rendertree_node_t*)renderable_node, MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE);
    mx_vector_append(&((mx_gl_rendertree_node_renderable_t*)children)->renderables, renderable);
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
        case MX_GL_RENDERTREE_NODE_TYPE_STATE:
            mx_vector_create(&node->children);
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE:
            mx_vector_create(&((mx_gl_rendertree_node_renderable_t*)node)->renderables);
            break;
    }
}

void _mx_gl_rendertree_node_free(mx_gl_rendertree_node_t* node) {
    switch (node->type) {
        case MX_GL_RENDERTREE_NODE_TYPE_ROOT:
        case MX_GL_RENDERTREE_NODE_TYPE_STATE:
            mx_vector_free(&node->children);
            break;
        case MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE:
            mx_vector_free(&((mx_gl_rendertree_node_renderable_t*)node)->renderables);
            break;
    }
}

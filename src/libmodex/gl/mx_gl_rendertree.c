#include "core/mx_memory.h"
#include "core/mx_vector.h"

#include "mx_gl_rendertree.h"

#include "string.h"

void _mx_rendertree_free(mx_rendertree_node_t* node);
void _mx_rendertree_node_create(mx_rendertree_node_t *const node, const mx_rendertree_node_type_t type);
void _mx_rendertree_node_free(mx_rendertree_node_t* node);

void mx_rendertree_create(mx_rendertree_t *const tree) {
    tree->root = MX_CALLOC(1, sizeof(mx_rendertree_node_root_t));
    _mx_rendertree_node_create(tree->root, MX_RENDERTREE_NODE_TYPE_ROOT);
}

void mx_rendertree_add_renderable(mx_rendertree_t *const tree, mx_renderable_t *const renderable) {
    renderable->getState(tree->state);

    mx_rendertree_node_state_t* state_node = NULL;
    mx_rendertree_node_renderable_t* renderable_node = NULL;
    mx_vector_t* children = &tree->root->children;

    for (size_t i = 0; i < _MX_RENDERTREE_NODE_STATE_COUNT; i++) {
        // find existing state at this level if it exists
        for (size_t j = 0; j < children->size; j++) {
            state_node = (mx_rendertree_node_state_t*)mx_vector_get(children, j);
            if (state_node->id == tree->state[i])
                break;
            state_node = NULL;
        }

        // add it if not found
        if (!state_node) {
            state_node = MX_CALLOC(1, sizeof(mx_rendertree_node_state_t));
            _mx_rendertree_node_create((mx_rendertree_node_t*)state_node, MX_RENDERTREE_NODE_TYPE_STATE);
            mx_vector_append(children, state_node);
        }

        children = &state_node->children;
    }
    
    // TODO: do something with renderable param
    renderable_node = MX_CALLOC(1, sizeof(mx_rendertree_node_renderable_t));
    _mx_rendertree_node_create((mx_rendertree_node_t*)renderable_node, MX_RENDERTREE_NODE_TYPE_RENDERABLE);
    mx_vector_append(children, renderable_node);
} 

void _mx_rendertree_free(mx_rendertree_node_t *node) {
    switch (node->type) {
        case MX_RENDERTREE_NODE_TYPE_ROOT:
        case MX_RENDERTREE_NODE_TYPE_STATE:
            for (size_t i = 0; i < node->children.size; i++) {
                _mx_rendertree_free(mx_vector_get(&node->children, i));
                _mx_rendertree_node_free(node);
            }
            break;
        case MX_RENDERTREE_NODE_TYPE_RENDERABLE:
            _mx_rendertree_node_free(node);
            break;
    }
}

void mx_rendertree_free(mx_rendertree_t* tree) {
    _mx_rendertree_free(tree->root);
}

void _mx_rendertree_node_create(mx_rendertree_node_t* node, const mx_rendertree_node_type_t type) {
    node->type = type;

    switch (node->type) {
        case MX_RENDERTREE_NODE_TYPE_ROOT:
        case MX_RENDERTREE_NODE_TYPE_STATE:
            mx_vector_create(&node->children);
            break;
        case MX_RENDERTREE_NODE_TYPE_RENDERABLE:
            break;
    }
}

void _mx_rendertree_node_free(mx_rendertree_node_t* node) {
    switch (node->type) {
        case MX_RENDERTREE_NODE_TYPE_ROOT:
        case MX_RENDERTREE_NODE_TYPE_STATE:
            mx_vector_free(&node->children);
            break;
        case MX_RENDERTREE_NODE_TYPE_RENDERABLE:
            break;
    }
}

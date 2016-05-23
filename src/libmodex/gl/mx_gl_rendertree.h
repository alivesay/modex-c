#ifndef H_MXRENDERTREE
#define H_MXRENDERTREE

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_vector.h"
#include "gl/mx_gl_common.h"
#endif





typedef struct {
    void (*getState)(uint64_t state[4]);
} mx_renderable_t;






typedef enum {
    MX_RENDERTREE_NODE_TYPE_ROOT = 0,
    MX_RENDERTREE_NODE_TYPE_STATE,
    MX_RENDERTREE_NODE_TYPE_RENDERABLE
} mx_rendertree_node_type_t;

typedef enum {
    MX_RENDERTREE_NODE_STATE_FBO = 0,
    MX_RENDERTREE_NODE_STATE_PROGRAM,
    MX_RENDERTREE_NODE_STATE_TEXTURE,
    MX_RENDERTREE_NODE_STATE_VBO,
    _MX_RENDERTREE_NODE_STATE_COUNT
} mx_rendertree_node_state_type_t;

typedef struct {
    mx_rendertree_node_type_t type;
    mx_vector_t children;
} mx_rendertree_node_t;

typedef struct {
    mx_rendertree_node_type_t type;
    mx_vector_t children;
    uint64_t state[_MX_RENDERTREE_NODE_STATE_COUNT];
} mx_rendertree_node_root_t;

typedef struct {
    mx_rendertree_node_type_t type;
    mx_vector_t children;
    mx_rendertree_node_state_type_t state_type;
    uint64_t id;
    // more attributes how?
} mx_rendertree_node_state_t;

typedef struct {
    mx_rendertree_node_type_t type;
    // some ref to a renderable?
    uint64_t name;
} mx_rendertree_node_renderable_t;

typedef struct {
    mx_rendertree_node_t* root;
    uint64_t state[_MX_RENDERTREE_NODE_STATE_COUNT];
} mx_rendertree_t;

void mx_rendertree_create(mx_rendertree_t *const tree);
void mx_rendertree_add_renderable(mx_rendertree_t *const tree, mx_renderable_t *const renderable);
void mx_rendertree_free(mx_rendertree_t* tree);
void mx_rendertree_dump(mx_rendertree_t* tree);

#endif // H_MXRENDERTREE

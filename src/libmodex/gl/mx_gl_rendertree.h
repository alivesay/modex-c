#ifndef H_MXGLRENDERTREE
#define H_MXGLRENDERTREE

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_vector.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_state.h"
#endif





typedef struct {
    const mx_gl_state_t *const (*getState) (void);
} mx_renderable_t;


typedef enum {
    MX_GL_RENDERTREE_NODE_TYPE_ROOT = 0,
    MX_GL_RENDERTREE_NODE_TYPE_STATE,
    MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE,
    _MX_GL_RENDERTREE_NODE_TYPE_COUNT
} mx_gl_rendertree_node_type_t;

typedef enum {
    MX_GL_RENDERTREE_NODE_STATE_CAPFLAGS = 0,
    MX_GL_RENDERTREE_NODE_STATE_FBO,
    MX_GL_RENDERTREE_NODE_STATE_PROGRAM,
    MX_GL_RENDERTREE_NODE_STATE_TEXTURE,
    MX_GL_RENDERTREE_NODE_STATE_VBO,
    _MX_GL_RENDERTREE_NODE_STATE_COUNT
} mx_gl_rendertree_node_state_type_t;

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t* children;
} mx_gl_rendertree_node_t;

typedef void (*mx_gl_rendertree_render_fn_t) (mx_vector_t *const renderables, const mx_gl_state_t *const state); 

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t* children;
} mx_gl_rendertree_node_root_t;

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t* children;
    mx_gl_rendertree_node_state_type_t state_type;
    void* state_property;
} mx_gl_rendertree_node_state_t;

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t* renderables;
} mx_gl_rendertree_node_renderable_t;

typedef struct {
    mx_gl_rendertree_node_t* root;
    mx_gl_state_t state;
    mx_gl_rendertree_render_fn_t render_fn;
} mx_gl_rendertree_t;

mx_gl_rendertree_t* mx_gl_rendertree_create(void);
void mx_gl_rendertree_init(mx_gl_rendertree_t *const tree);
void mx_gl_rendertree_destroy(mx_gl_rendertree_t* tree);
void mx_gl_rendertree_free(mx_gl_rendertree_t** tree);
void mx_gl_rendertree_add_renderable(mx_gl_rendertree_t *const tree, mx_renderable_t *const renderable);
void mx_gl_rendertree_set_render_fn(mx_gl_rendertree_t *const tree, const mx_gl_rendertree_render_fn_t render);
void mx_gl_rendertree_render(void);
void mx_gl_rendertree_dump(mx_gl_rendertree_t* tree);

#endif // H_MXGLRENDERTREE

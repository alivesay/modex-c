#ifndef H_MXGLRENDERTREE
#define H_MXGLRENDERTREE

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_vector.h"
#include "gl/mx_gl_common.h"
#endif





typedef struct {
    void (*getState)(uint64_t state[4]);
} mx_renderable_t;


typedef enum {
    FBO         = 0x00000001,
    BLEND       = 0x00000002,
    PROGRAM     = 0x00000004,
    TEXTURE     = 0x00000008,
    VBO         = 0x00000016,
    PRIMATIVE   = 0x00000032,
    _STATE_FLAG_COUNT = 5
} mx_gl_rendertree_state_flag_t;


typedef enum {
    MX_GL_RENDERTREE_NODE_TYPE_ROOT = 0,
    MX_GL_RENDERTREE_NODE_TYPE_STATE,
    MX_GL_RENDERTREE_NODE_TYPE_RENDERABLE
} mx_gl_rendertree_node_type_t;

typedef enum {
    MX_GL_RENDERTREE_NODE_STATE_FBO = 0,
    MX_GL_RENDERTREE_NODE_STATE_PROGRAM,
    MX_GL_RENDERTREE_NODE_STATE_TEXTURE,
    MX_GL_RENDERTREE_NODE_STATE_VBO,
    _MX_GL_RENDERTREE_NODE_STATE_COUNT
} mx_gl_rendertree_node_state_type_t;

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t children;
} mx_gl_rendertree_node_t;

typedef void (*mx_gl_rendertree_render_fn_t) (mx_vector_t *const renderables, uint64_t state[_MX_GL_RENDERTREE_NODE_STATE_COUNT]);

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t children;
    uint64_t state[_MX_GL_RENDERTREE_NODE_STATE_COUNT];
} mx_gl_rendertree_node_root_t;

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t children;
    mx_gl_rendertree_node_state_type_t state_type;
    uint64_t id;
    // more attributes how?
} mx_gl_rendertree_node_state_t;

typedef struct {
    mx_gl_rendertree_node_type_t type;
    mx_vector_t renderables;
} mx_gl_rendertree_node_renderable_t;

typedef struct {
    mx_gl_rendertree_node_t* root;
    uint64_t state[_MX_GL_RENDERTREE_NODE_STATE_COUNT];
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

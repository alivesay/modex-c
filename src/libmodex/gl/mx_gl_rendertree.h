#ifndef H_MXRENDERTREE
#define H_MXRENDERTREE

#ifndef H_MODEX
#endif

enum mx_rendertree_node_type_t {
    MX_RENDERTREE_NODE_FBO = 0,
    MX_RENDERTREE_NODE_PROGRAM,
    MX_RENDERTREE_NODE_TEXTURE,
    MX_RENDERTREE_NODE_VAO
};

typedef struct {
    mx_rendertree_node_type_t type;
    mx_rendertree_node_t*; 
    // chidren
    // siblings
} mx_rendertree_node_t;

typedef struct {
    int fbo;
    int program;
    int texture; // --> from some atlas
    GLenum primative_type; // eg, tri-strep..
    int vao/vbo; // ?
} mx_rendertree_state_t;

#endif // H_MXRENDERTREE

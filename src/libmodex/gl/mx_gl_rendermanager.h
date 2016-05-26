#ifndef H_MXRENDERMANAGER
#define H_MXRENDERMANAGER

#ifndef H_MODEX
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_rendertree.h"
#endif

typedef struct {
   mx_gl_rendertree_t* rendertree; 
} mx_gl_rendermanager_t;

mx_gl_rendermanager_t* mx_gl_rendermanager_create(void);
void mx_gl_rendermanager_init(mx_gl_rendermanager_t *const manager);
void mx_gl_rendermanager_destroy(mx_gl_rendermanager_t* manager);
void mx_gl_rendermanager_free(mx_gl_rendermanager_t** manager);
void mx_gl_rendermanager_render(const mx_gl_rendermanager_t *const manager);

#endif // H_MXRENDERMANAGER

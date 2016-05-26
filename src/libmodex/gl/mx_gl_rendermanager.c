#include "core/mx_memory.h"
#include "gl/mx_gl_rendertree.h"

#include "mx_gl_rendermanager.h"

mx_gl_rendermanager_t* mxl_gl_rendermanager_create(void) {
    mx_gl_rendermanager_t* manager = MX_CALLOC(1, sizeof(mx_gl_rendermanager_t));
    mx_gl_rendermanager_init(manager);

    return manager;
}

void mx_gl_rendermanager_init(mx_gl_rendermanager_t *const manager) {
    manager->rendertree = mx_gl_rendertree_create();
}

void mx_gl_rendermanager_destroy(mx_gl_rendermanager_t* manager) {
    mx_gl_rendertree_free(&manager->rendertree);
}

void mx_gl_rendermanager_free(mx_gl_rendermanager_t** manager) {
    mx_gl_rendermanager_destroy(*manager);
    MX_FREE(*manager);
    *manager = NULL;
}

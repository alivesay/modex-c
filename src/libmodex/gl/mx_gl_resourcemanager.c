#include "core/mx_types.h"
#include "core/mx_memory.h"
#include "core/mx_uintmap.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_vbo.h"
#include "gl/mx_gl_program.h"

#include "mx_gl_resourcemanager.h"

mx_gl_resourcemanager_t* mx_gl_resourcemanager_create(void) {
    mx_gl_resourcemanager_t* manager = MX_MALLOC(sizeof(mx_gl_resourcemanager_t));
    mx_gl_resourcemanager_init(manager);
    return manager;
}

void mx_gl_resourcemanager_init(mx_gl_resourcemanager_t *const manager) {
    manager->_vbo_id_map = mx_uintmap_create();
}

void mx_gl_resourcemanager_destroy(mx_gl_resourcemanager_t *const manager) {
    mx_uintmap_free(&manager->_vbo_id_map);
    manager->_vbo_id_map = NULL;
}

void mx_gl_resourcemanager_free(mx_gl_resourcemanager_t** manager) {
    mx_gl_resourcemanager_destroy(*manager);
    MX_FREE(*manager);
    *manager = NULL;
}

mx_gl_resource_t mx_gl_resourcemanager_v_create(mx_gl_resourcemanager_t *const manager,
                                                const mx_gl_resource_options_t *const options) {

    mx_gl_resource_t resource = { 0 };
    
    switch (options->type) {
        case MX_GL_RESOURCE_TYPE_VBO: {
            const mx_gl_resource_options_vbo_t *const vbo_options = (const mx_gl_resource_options_vbo_t *const)options;
            mx_gl_vbo_t* vbo = mx_gl_vbo_create(vbo_options->size, vbo_options->usage);
            resource.id = mx_uintmap_add(manager->_vbo_id_map, vbo);
            resource.type = MX_GL_RESOURCE_TYPE_VBO;
            break;
        }
    }

    return resource;
}

void mx_gl_resourcemanager_resource_free(mx_gl_resourcemanager_t *const manager, const mx_gl_resource_t resource) {
    switch (resource.type) {
        case MX_GL_RESOURCE_TYPE_VBO: {
            mx_gl_vbo_t* vbo = (mx_gl_vbo_t*)mx_uintmap_remove(manager->_vbo_id_map, resource.id);
            if (vbo) mx_gl_vbo_free(&vbo);
            break;
        }
        case MX_GL_RESOURCE_TYPE_PROGRAM: {
            mx_gl_program_t* program = (mx_gl_program_t*)mx_uintmap_remove(manager->_program_id_map, resource.id);
            if (program) mx_gl_program_free(&program);
            break;
        }
    }
}

void* mx_gl_resourcemanager_resource_get(mx_gl_resourcemanager_t *const manager, const mx_gl_resource_t resource) {
    switch (resource.type) {
        case MX_GL_RESOURCE_TYPE_VBO:
            return mx_uintmap_get(manager->_vbo_id_map, resource.id);
            break;
        case MX_GL_RESOURCE_TYPE_PROGRAM:
            return mx_uintmap_get(manager->_program_id_map, resource.id);
            break;
    }

    return NULL;
}

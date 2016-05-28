#ifndef H_MXGLRESOURCEMANAGER
#define H_MXGLRESOURCEMANAGER

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_uintmap.h"
#include "gl/mx_gl_common.h"
#include "gl/mx_gl_vbo.h"
#include "gl/mx_gl_program.h"
#endif

typedef enum {
    MX_GL_RESOURCE_TYPE_INVALID = 0,
    MX_GL_RESOURCE_TYPE_VBO,
    MX_GL_RESOURCE_TYPE_PROGRAM,
    _MX_GL_RESOURCE_TYPE_COUNT
} mx_gl_resource_type_t;

typedef struct {
    mx_gl_resource_type_t type;
    uint64_t id;
} mx_gl_resource_t;

typedef struct {
    mx_gl_resource_type_t type;
} mx_gl_resource_options_t;

typedef struct {
    mx_gl_resource_type_t type;
    size_t size;
    GLenum usage;
} mx_gl_resource_options_vbo_t;

typedef struct {
    mx_uintmap_t* _vbo_id_map;
    mx_uintmap_t* _program_id_map;
} mx_gl_resourcemanager_t;

mx_gl_resourcemanager_t* mx_gl_resourcemanager_create(void);
void mx_gl_resourcemanager_init(mx_gl_resourcemanager_t *const manager);
void mx_gl_resourcemanager_destroy(mx_gl_resourcemanager_t *const manager);
void mx_gl_resourcemanager_free(mx_gl_resourcemanager_t** manager);

mx_gl_resource_t mx_gl_resourcemanager_resource_create(mx_gl_resourcemanager_t *const manager,
                                                       const size_t size,
                                                       const GLenum usage);
void mx_gl_resourcemanager_resource_free(mx_gl_resourcemanager_t *const manager, const mx_gl_resource_t resource);
void* mx_gl_resourcemanager_resource_get(mx_gl_resourcemanager_t *const manager, const mx_gl_resource_t resource);

#endif // H_MXGLRESOURCEMANAGER

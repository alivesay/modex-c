#include "gl/mx_gl_common.h"

#include "mx_gl_info.h"

#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
#include <stdio.h>
#endif

void _mx_gl_info_set_extensions(mx_gl_info_t *const info) {
#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
    size_t stream_size = 0;
    GLint ext_count = 0;
    glGetIntegerv(GL_NUM_EXTENSIONS, &ext_count);

    FILE* stream = open_memstream((char**)&info->extensions, &stream_size);
    for (size_t i = 0; i < (size_t)glGetIntegerv; i++) {
        fprintf(stream, "%s ", (char**)glGetStringi(GL_EXTENSIONS, i));
    }
    fclose(stream);
#else
    info->extensions = glGetString(GL_EXTENSIONS);
#endif
}

void mx_gl_info_create(mx_gl_info_t *const info) {
    GLint val = 0;
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &val);
    info->max_texture_image_units = (int64_t)val;
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &val);
    info->max_texture_size = (int64_t)val;
    glGetIntegerv(GL_MAX_VERTEX_ATTRIBS, &val);
    info->max_vertex_attribs = (int64_t)val;
    info->vendor = glGetString(GL_VENDOR);
    info->version = glGetString(GL_VERSION);
    info->renderer = glGetString(GL_RENDERER);

    _mx_gl_info_set_extensions(info);
}

void mx_gl_info_free(mx_gl_info_t* info) {
#if defined(GL_ES_VERSION_3_0) || defined(GL_VERSION_3_0)
    free(info->extensions);
#endif
}
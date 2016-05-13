#include "gl/mx_gl_common.h"

#include "mx_gl_info.h"

void mx_gl_info_query(mx_gl_info_t *const info) {
    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &info->max_texture_image_units);
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &info->max_texture_size);
    info->vendor = glGetString(GL_VENDOR);
    info->version = glGetString(GL_VENDOR);
    info->renderer = glGetString(GL_VENDOR);
}

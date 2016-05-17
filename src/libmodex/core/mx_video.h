#ifndef H_MXVIDEO
#define H_MXVIDEO

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_color.h"
#include "sdl/mx_sdl_screen.h"
#include "gl/mx_gl.h"
#endif

#include <SDL2/SDL.h>

typedef struct {
    mx_gl_t gl;
    mx_sdl_screen_t screen;

    GLfloat viewport[4];
    GLfloat projection_matrix[16];
    GLuint projection_ref;

    GLuint vbo;
    GLuint vao;

} mx_video_t;

void mx_video_create(mx_video_t *const video);
void mx_video_mode_set(uint16_t width,
                       uint16_t height,
                       uint8_t bpp,
                       bool fullscreen);
void mx_video_view_set(void);
void mx_video_render_begin(const mx_video_t *const video);
void mx_video_render_end(const mx_video_t *const video);
void mx_video_draw_rect(const float x,
                        const float y,
                        const float width,
                        const float height);
void mx_video_fill_rect(const float x,
                        const float y,
                        const float width,
                        const float height);
void mx_video_set_draw_color(const mx_color4b_t *color);
void mx_video_free(mx_video_t* video);

#endif // H_MXVIDEO

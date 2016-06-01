#ifndef H_MXVIDEO
#define H_MXVIDEO

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_color.h"
#include "sdl/mx_sdl.h"
#include "sdl/mx_sdl_screen.h"
#include "gl/mx_gl.h"
#endif

#include <SDL2/SDL.h>

typedef struct {
    uint16_t width;
    uint16_t height;
    uint8_t bpp;
    bool fullscreen;
} mx_video_mode_t;

typedef struct {
    mx_gl_t* _gl;
    mx_sdl_t* _sdl_ref;
    mx_sdl_screen_t* _sdl_screen;

//    GLfloat viewport[4];
//    GLfloat projection_matrix[16];
    GLuint projection_ref;

//    GLuint vbo;
//    GLuint vao;

} mx_video_t;

mx_video_t* mx_video_create(mx_sdl_t *const sdl);
mx_video_t* mx_video_init(mx_video_t *const video, mx_sdl_t *const sdl);
void mx_video_destroy(mx_video_t *const video);
void mx_video_free(mx_video_t** video);



void mx_video_mode_set(mx_video_t *const video, const mx_video_mode_t video_mode);
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

#endif // H_MXVIDEO

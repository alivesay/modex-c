#ifndef H_MXVIDEO
#define H_MXVIDEO

#ifndef H_MODEX
#include "mx_types.h"
#include "mx_color.h"
#endif

#include <SDL2/SDL.h>

typedef struct {
    uint16_t width, height;
    
    SDL_Window *window;
    SDL_GLContext glcontext;

    GLfloat viewport[4];
    GLfloat projection_matrix[16];
    GLuint projection_ref;
    GLuint shader_program;
    GLuint fragment_shader;
    GLuint vertex_shader;

    GLuint vbo;
    GLuint vao;

} mx_video_t;

extern mx_video_t g_mx_video;

void mx_video_init(void);
void mx_video_mode_set(uint16_t width,
                       uint16_t height,
                       uint8_t bpp,
                       bool fullscreen);
void mx_video_view_set(void);
void mx_video_draw_begin(void);
void mx_video_draw_end(void);
void mx_video_draw_rect(const float x,
                        const float y,
                        const float width,
                        const float height);
void mx_video_fill_rect(const float x,
                        const float y,
                        const float width,
                        const float height);
void mx_video_set_draw_color(const mx_color4b_t *color);
void mx_video_quit(void);

#endif // H_MXVIDEO

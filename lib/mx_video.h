#ifndef H_MXVIDEO
#define H_MXVIDEO

#include "mx_types.h"
#include "mx_color.h"

#include <SDL2/SDL.h>

typedef struct {
    uint16 width, height;
    
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

void mx_video_init(void);
void mx_video_mode_set(uint16 width, uint16 height, uint8 bpp, bool fullscreen);
void mx_video_view_set(void);
void mx_video_draw_begin(void);
void mx_video_draw_end(void);
void mx_video_draw_rect(const real32 x, const real32 y, const real32 width, const real32 height);
void mx_video_fill_rect(const real32 x, const real32 y, const real32 width, const real32 height);
void mx_video_set_draw_color(const mx_color4b_t *color);
void mx_video_quit(void);

void _mx_video_gl_init(void);
void _mx_video_view_set(void);
void _mx_video_ortho(GLfloat *matrix, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top);
void _mx_video_dump_shader_log(GLuint shader);

#endif // H_MXVIDEO

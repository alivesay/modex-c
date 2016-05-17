#include "core/mx_types.h"
#include "core/mx_log.h"
#include "core/mx_math.h"
#include "sdl/mx_sdl.h"
#include "sdl/mx_sdl_screen.h"
#include "gl/mx_gl.h"

#include "mx_video.h"

#include <stdlib.h>
#include <stdio.h>

/* global video state */
    GLfloat triangle[] = {
        160.0f, 10.0f,
        310.0f, 230.0f,
        10.0f, 230.0f,
    };

static uint16_t _mx_video_initial_width = 320;
static uint16_t _mx_video_initial_height = 240;

void _mx_video_gl_init(void);
void _mx_video_view_set(void);
void _mx_video_ortho(GLfloat *matrix,
                     GLfloat left,
                     GLfloat right,
                     GLfloat bottom,
                     GLfloat top);

void mx_video_create(mx_video_t *const video) {
    mx_sdl_video_init();
    mx_sdl_screen_create(&video->screen);
    mx_gl_create(&video->gl);
}

void _mx_video_gl_init(void) {
/*
    glGenBuffers(1, &g_mx_video.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, g_mx_video.vbo);
    glBufferData(GL_ARRAY_BUFFER, 4096, NULL, GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(triangle), triangle);

    glGenVertexArrays(1, &g_mx_video.vao);
    glBindVertexArray(g_mx_video.vao);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(GL_FLOAT), (void*)0);

    MX_GL_ERRCHK(MX_LOG_ERR);
*/
}

void mx_video_mode_set(uint16_t width, uint16_t height, uint8_t bpp, bool fullscreen) {
    /*
    // TODO: what if it exists/
    g_mx_video.window = SDL_CreateWindow(
        "MODEX",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        width,
        height,
        SDL_WINDOW_OPENGL);
    
    g_mx_video.glcontext = SDL_GL_CreateContext(g_mx_video.window); 

    g_mx_video.width = width;
    g_mx_video.height = height;

    _mx_video_gl_init();
    */
}

void mx_video_view_set() {
    /*
    glGetFloatv(GL_VIEWPORT, g_mx_video.viewport);

    _mx_video_ortho(g_mx_video.projection_matrix, 0.0f, g_mx_video.viewport[2], g_mx_video.viewport[3], 0.0f);

    g_mx_video.projection_ref = glGetUniformLocation(g_mx_video.shader_program, "uProjectionMatrix");

    glUniformMatrix4fv(g_mx_video.projection_ref, 1, GL_FALSE, g_mx_video.projection_matrix);

    glClearColor(32/255.0f, 64/255.0f, 144/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    MX_GL_ERRCHK(MX_LOG_ERR);
*/
}

void _mx_video_ortho(GLfloat *matrix, GLfloat left, GLfloat right, GLfloat bottom, GLfloat top) {
    const GLfloat z_near = -1.0f,
                  z_far = 1.0f,
                  inv_z = 1.0f / (z_far - z_near),
                  inv_y = 1.0f / (top - bottom),
                  inv_x = 1.0f / (right - left);

    *matrix++ = 2.0f * inv_x;
    *matrix++ = 0.0f;
    *matrix++ = 0.0f;
    *matrix++ = 0.0f;

    *matrix++ = 0.0f;
    *matrix++ = 2.0f * inv_y;
    *matrix++ = 0.0f;
    *matrix++ = 0.0f;

    *matrix++ = 0.0f;
    *matrix++ = 0.0f;
    *matrix++ = -2.0f * inv_z;
    *matrix++ = 0.0f;

    *matrix++ = -(right + left) * inv_x;
    *matrix++ = -(top + bottom) * inv_y;
    *matrix++ = -(z_far + z_near) * inv_z;;
    *matrix++ = 1.0f;
}

void mx_video_render_begin(const mx_video_t *const video) {
    //glEnable(GL_DEPTH_TEST);
    //glClearDepthf(1.0f);
    glClearColor(32/255.0f, 64/255.0f, 144/255.0f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    triangle[0]++;
    glBindBuffer(GL_ARRAY_BUFFER, video->vbo);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(triangle), triangle);


    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void mx_video_render_end(const mx_video_t *const video) {
    mx_sdl_screen_swap(&video->screen);
    // glDisable(GL_DEPTH_TEST);
    MX_GL_ERRCHK(MX_LOG_ERR);
}

void mx_video_free(mx_video_t* video) {
    mx_gl_free(&video->gl);
    mx_sdl_screen_free(&video->screen);
    mx_sdl_shutdown();
}

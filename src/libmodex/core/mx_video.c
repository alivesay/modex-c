#include "core/mx_types.h"
#include "core/mx_log.h"
#include "core/mx_math.h"
#include "core/mx_memory.h"
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

mx_video_t* mx_video_create(mx_sdl_t *const sdl) {
    mx_video_t* video = MX_CALLOC(1, sizeof(mx_video_t));
    return mx_video_init(video, sdl);
}

mx_video_t* mx_video_init(mx_video_t *const video, mx_sdl_t *const sdl) {
    // TODO: might need to reverse the order here
    mx_sdl_video_init(sdl);
    video->_sdl_screen = mx_sdl_screen_create();
    video->_gl = mx_gl_create();
    video->_sdl_ref = sdl;
    return video;
}

void mx_video_destroy(mx_video_t *const video) {
    mx_sdl_screen_free(&video->_sdl_screen);
    mx_sdl_video_shutdown(video->_sdl_ref);
    mx_gl_free(&video->_gl);
}

void mx_video_free(mx_video_t** video) {
    mx_video_destroy(*video);
    MX_FREE(*video);
    *video = NULL;
}

void mx_video_mode_set(mx_video_t *const video, const mx_video_mode_t video_mode) {
    // TODO: sdl_screen currently has a fixed video mode
    // set gl viewport
    mx_gl_set_projection_ortho(video->_gl);
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

void mx_video_render_begin(const mx_video_t *const video) {
    //glEnable(GL_DEPTH_TEST);
    //glClearDepthf(1.0f);
//    glClearColor(32/255.0f, 64/255.0f, 144/255.0f, 1.0f);
//    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
//    triangle[0]++;
//    glBindBuffer(GL_ARRAY_BUFFER, video->vbo);
//    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(triangle), triangle);


//    glDrawArrays(GL_TRIANGLES, 0, 3);

    mx_gl_draw_begin(video->_gl);
}

void mx_video_render_end(const mx_video_t *const video) {
    mx_gl_draw_end(video->_gl);
    mx_sdl_screen_swap(video->_sdl_screen);
    // glDisable(GL_DEPTH_TEST);
    MX_GL_ERRCHK(MX_LOG_ERR);
}

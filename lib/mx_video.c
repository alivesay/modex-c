#include "mx_types.h"
#include "mx_math.h"
#include "mx_video.h"
#include "gl/mx_gl_common.h"

#include <stdlib.h>
#include <stdio.h>

#include <epoxy/gl.h>
#include <epoxy/glx.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

/* global video state */
mx_video_t g_mx_video = { 0 };
//TODO: convert classes to ref passing style

#define MX_SCREEN_WIDTH 320
#define MX_SCREEN_HEIGHT 240
#define MX_SCREEN_BPP 8

void _mx_debug_opengl_errchk(char *file, int line) {
    GLenum err = glGetError();

    if (err != GL_NO_ERROR) {
        printf("OpenGL error [%s:%d]: %d\n", file, line, err);
    }
}


void mx_video_init(void) {
    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL error: %s\n", SDL_GetError());
        // TODO
    }

    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
}

void _mx_video_gl_init(void) {
    GLint max_tex_image_units;
    GLint max_tex_size;

    glGetIntegerv(GL_MAX_TEXTURE_IMAGE_UNITS, &max_tex_image_units);
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex_size);

    const char *vertexsrc = \
        "precision highp float;" \
        "uniform mat4 uProjectionMatrix;" \
        "attribute vec2 Position;" \
        "void main() {" \
        "   gl_Position = uProjectionMatrix * vec4(Position, 0.0, 1.0);" \
        "}";

    const char *fragmentsrc = \
        "precision highp float;" \
        "vec4 color = vec4(1.0,0.0,1.0,1.0);" \
        "void main() {" \
        "   if (mod(gl_FragCoord.y, 2.0f) < 1.0) {" \
        "       gl_FragColor = color;" \
        "   } else {" \
        "       gl_FragColor = vec4(0.0, 0.0, 0.0, 0.0);" \
        "   }" \
        "}";

    const GLfloat triangle[] = {
        200.0f, 10.0f,
        10.0f, 200.0f,
        400.0f, 200.0f
    };

    glGenBuffers(1, &g_mx_video.vbo);
    glBindBuffer(GL_ARRAY_BUFFER, g_mx_video.vbo);
    glBufferData(GL_ARRAY_BUFFER, 4096, NULL, GL_DYNAMIC_DRAW);
    glBufferSubData(GL_ARRAY_BUFFER, 0, sizeof(triangle), triangle);

    glGenVertexArrays(1, &g_mx_video.vao);
    glBindVertexArray(g_mx_video.vao);
    glEnableVertexAttribArray(0);
    glVertexAttribPointer(0, 2, GL_FLOAT, false, 2 * sizeof(GL_FLOAT), (void*)0);

    g_mx_video.shader_program = glCreateProgram();
    g_mx_video.fragment_shader = glCreateShader(GL_FRAGMENT_SHADER);
    g_mx_video.vertex_shader = glCreateShader(GL_VERTEX_SHADER);
    
    glShaderSource(g_mx_video.fragment_shader, 1, &fragmentsrc, NULL);
    glCompileShader(g_mx_video.fragment_shader);

    GLint compiled_ok;
    glGetShaderiv(g_mx_video.fragment_shader, GL_COMPILE_STATUS, &compiled_ok);
    if (!compiled_ok) {
        printf("Shader compilation failed. :(\n");
        _mx_video_dump_shader_log(g_mx_video.fragment_shader);
    } else {
        glAttachShader(g_mx_video.shader_program, g_mx_video.fragment_shader);
    }

    glShaderSource(g_mx_video.vertex_shader, 1, &vertexsrc, NULL);
    glCompileShader(g_mx_video.vertex_shader);
 
    glGetShaderiv(g_mx_video.vertex_shader, GL_COMPILE_STATUS, &compiled_ok);
    if (!compiled_ok) {
        printf("Shader compilation failed. :(\n");
        _mx_video_dump_shader_log(g_mx_video.vertex_shader);
    } else {
        glAttachShader(g_mx_video.shader_program, g_mx_video.vertex_shader);
    }

    glLinkProgram(g_mx_video.shader_program);
    glUseProgram(g_mx_video.shader_program);

    printf("GL_VENDOR:\t%s\n", glGetString(GL_VENDOR));
    printf("GL_RENDERER:\t%s\n", glGetString(GL_RENDERER));
    printf("GL_VERSION:\t%s\n", glGetString(GL_VERSION));
    printf("GL_EXTENSIONS:\t%s\n", glGetString(GL_EXTENSIONS));
    printf("GL_MAX_TEXTURE_UNITS:\t%d\n", (int)max_tex_image_units);
    printf("GL_MAX_TEXTURE_SIZE:\t%d\n", (int)max_tex_size);

    MX_GL_ERRCHK();
}

void mx_video_mode_set(uint16 width, uint16 height, uint8 bpp, bool fullscreen) {
    // TODO: what if it exists/


    g_mx_video.window = SDL_CreateWindow(
        "MODEX",
        0,
        0,
        width,
        height,
        SDL_WINDOW_OPENGL);
    
    g_mx_video.glcontext = SDL_GL_CreateContext(g_mx_video.window); 

    g_mx_video.width = width;
    g_mx_video.height = height;

    _mx_video_gl_init();
}

void mx_video_view_set() {
    glGetFloatv(GL_VIEWPORT, g_mx_video.viewport);

    _mx_video_ortho(g_mx_video.projection_matrix, 0.0f, g_mx_video.viewport[2], g_mx_video.viewport[3], 0.0f);

    g_mx_video.projection_ref = glGetUniformLocation(g_mx_video.shader_program, "uProjectionMatrix");

    glUniformMatrix4fv(g_mx_video.projection_ref, 1, GL_FALSE, g_mx_video.projection_matrix);

    glClearColor(0.3f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    
    MX_GL_ERRCHK();
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

void _mx_video_dump_shader_log(GLuint shader) {
    GLint log_len;
    glGetShaderiv(shader, GL_INFO_LOG_LENGTH, &log_len);
    GLchar log[log_len];
    glGetShaderInfoLog(shader, log_len, &log_len, log);
    printf("Shader error: %s\n", log);
}

void mx_video_draw_begin(void) {
    //glEnable(GL_DEPTH_TEST);
    //glClearDepthf(1.0f);
    glClearColor(0.3f, 0.4f, 0.4f, 1.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void mx_video_draw_end(void) {
    SDL_GL_SwapWindow(g_mx_video.window);
    // glDisable(GL_DEPTH_TEST);
    MX_GL_ERRCHK();
}

void mx_video_quit(void) {
    SDL_GL_DeleteContext(g_mx_video.glcontext);
    SDL_DestroyWindow(g_mx_video.window);
    SDL_Quit();
}

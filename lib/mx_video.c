#include "mx_types.h"
#include "mx_math.h"
#include "mx_video.h"

#include <stdlib.h>
#include <stdio.h>

#include <epoxy/gl.h>
#include <epoxy/glx.h>
#include <GLFW/glfw3.h>

/* global video state */
mx_video_t g_mx_video;

#define MX_SCREEN_WIDTH 320
#define MX_SCREEN_HEIGHT 240
#define MX_SCREEN_BPP 8

void mx_video_init(void) {
    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 2);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_ES_API);
    glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
}

void mx_video_mode_set(uint16 width, uint16 height, uint8 bpp, bool fullscreen) {
    GLFWwindow *window = glfwCreateWindow(width, height, "MODEX", fullscreen ? glfwGetPrimaryMonitor() : NULL, NULL);
    
    if (NULL == g_mx_video.window) {
        printf("glfwCreateWindow failed :(\n");
    }

    glfwMakeContextCurrent(window);

    g_mx_video.width = width;
    g_mx_video.height = height;
    g_mx_video.bpp = bpp;
    g_mx_video.fullscreen = fullscreen;
    g_mx_video.window = window;


    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);

    GLint max_tex_units;
    GLint max_tex_size;

    glGetIntegerv(GL_MAX_TEXTURE_UNITS, &max_tex_units);
    glGetIntegerv(GL_MAX_TEXTURE_SIZE, &max_tex_size);


    const char *vertexsrc = \
        "#version 330\n" \
        "layout(location = 0) in vec2 inCoord;\n" \
        "uniform mat4 uProjectionMatrix;\n" \
        "void main()\n" \
        "{\n" \
        "    gl_Position = uProjectionMatrix*(vec4(inCoord, 0, 1.0));\n" \
        "}\n";

    const char *fragmentsrc = \
        "#version 330 \n" \
        "out vec4 outFragColor;\n" \
        "vec4 DebugMagenta(){ return vec4(1.0, 0.0, 1.0, 1.0); }\n" \
        "void main() \n" \
        "{\n" \
        "   outFragColor = DebugMagenta();\n" \
        "}\n";

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
    } else {
        glAttachShader(g_mx_video.shader_program, g_mx_video.fragment_shader);
    }

    glShaderSource(g_mx_video.vertex_shader, 1, &vertexsrc, NULL);
    glCompileShader(g_mx_video.vertex_shader);
 
    glGetShaderiv(g_mx_video.vertex_shader, GL_COMPILE_STATUS, &compiled_ok);
    if (!compiled_ok) {
        printf("Shader compilation failed. :(\n");
    } else {
        glAttachShader(g_mx_video.shader_program, g_mx_video.vertex_shader);
    }

    glLinkProgram(g_mx_video.shader_program);
    glUseProgram(g_mx_video.shader_program);

    printf("GL_VENDOR:\t%s\n", glGetString(GL_VENDOR));
    printf("GL_RENDERER:\t%s\n", glGetString(GL_RENDERER));
    printf("GL_VERSION:\t%s\n", glGetString(GL_VERSION));
    printf("GL_EXTENSIONS:\t%s\n", glGetString(GL_EXTENSIONS));
    printf("GL_MAX_TEXTURE_UNITS:\t%d\n", (int)max_tex_units);
    printf("GL_MAX_TEXTURE_SIZE:\t%d\n", (int)max_tex_size);
}

void mx_video_view_set() {
    glGetFloatv(GL_VIEWPORT, g_mx_video.viewport);

    g_mx_video.projection_ref = glGetUniformLocation(g_mx_video.shader_program, "uProjectionMatrix");

    glUniformMatrix4fv(g_mx_video.projection_ref, 1, GL_FALSE, g_mx_video.projection_matrix);

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 
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

void mx_video_draw_begin(void) {
    glEnable(GL_DEPTH_TEST);
    glClearDepthf(1.0f);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST); 

    glDrawArrays(GL_TRIANGLES, 0, 3);
}

void mx_video_draw_end(void) {
    glfwSwapBuffers(g_mx_video.window);
    glDisable(GL_DEPTH_TEST);
}

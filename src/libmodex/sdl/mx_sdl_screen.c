#include "core/mx_types.h"
#include "mx_sdl_screen.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

static uint16_t _mx_video_initial_width = 320;
static uint16_t _mx_video_initial_height = 240;

void mx_sdl_screen_create(mx_sdl_screen_t *const screen) {
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 2);
    SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);
    SDL_GL_SetAttribute(SDL_GL_ACCELERATED_VISUAL, 1);
    SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
    SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
    
    screen->window = SDL_CreateWindow(
        "MODEX",
        SDL_WINDOWPOS_UNDEFINED,
        SDL_WINDOWPOS_UNDEFINED,
        _mx_video_initial_width,
        _mx_video_initial_height,
        SDL_WINDOW_OPENGL);
    
    screen->context = SDL_GL_CreateContext(screen->window); 
}

void mx_sdl_screen_free(mx_sdl_screen_t* screen) {
    SDL_DestroyWindow(screen->window);
}

void mx_sdl_screen_swap(const mx_sdl_screen_t *const screen) {
    SDL_GL_SwapWindow(screen->window);
}

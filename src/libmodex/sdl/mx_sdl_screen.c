#include "core/mx_types.h"
#include "core/mx_memory.h"
#include "mx_sdl_screen.h"

#include <SDL2/SDL.h>
#include <SDL2/SDL_opengles2.h>

// TODO: move
static uint16_t _mx_video_initial_width = 320;
static uint16_t _mx_video_initial_height = 240;

mx_sdl_screen_t* mx_sdl_screen_create(void) {
    mx_sdl_screen_t* screen = MX_CALLOC(1, sizeof(mx_sdl_screen_t));
    return mx_sdl_screen_init(screen);
}

mx_sdl_screen_t* mx_sdl_screen_init(mx_sdl_screen_t *const screen) {
    // TODO: support other depth sizes, etc
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
    if (!screen->window) goto mx_error;
    
    screen->context = SDL_GL_CreateContext(screen->window); 
    if (!screen->context) goto mx_error;

    return screen;

mx_error:
        MX_LOG(MX_LOG_ERR, SDL_GetError());
        return NULL;
}

void mx_sdl_screen_destroy(mx_sdl_screen_t *const screen) {
    SDL_GL_DeleteContext(screen->context);
    SDL_DestroyWindow(screen->window);
}

void mx_sdl_screen_free(mx_sdl_screen_t** screen) {
    mx_sdl_screen_destroy(*screen);
    MX_FREE(*screen);
    *screen = NULL;
}

void mx_sdl_screen_swap(const mx_sdl_screen_t *const screen) {
    SDL_GL_SwapWindow(screen->window);
}

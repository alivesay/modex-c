#ifndef H_MXSDLSCREEN
#define H_MXSDLSCREEN

#ifndef H_MODEX
#endif

#include <SDL2/SDL.h>

typedef struct {
    SDL_Window* window;
    SDL_GLContext* context; 
} mx_sdl_screen_t;

void mx_sdl_screen_create(mx_sdl_screen_t *const screen);
void mx_sdl_screen_free(mx_sdl_screen_t* screen);
void mx_sdl_screen_swap(const mx_sdl_screen_t *const screen);

// toggle fullscreen
// set videomode
// toggle vsync

#endif // H_MXSDLSCREEN

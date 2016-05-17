#include "core/mx_types.h"
#include "core/mx_log.h"

#include "mx_sdl.h"

#include <SDL2/SDL.h>

typedef struct {
    bool initialized;
    bool video_initialized;
} _mx_sdl_status_t;

static _mx_sdl_status_t _mx_sdl_status = {0};

void mx_sdl_init(void) {
    if (_mx_sdl_status.initialized) {
        MX_LOG(MX_LOG_ERR, "SDL already initalized");
        return;
    }

    if (SDL_Init(0)) {
        MX_LOG(MX_LOG_CRIT, SDL_GetError());
        return;
    }

    _mx_sdl_status.initialized = true;
}

void mx_sdl_shutdown(void) {
    if (_mx_sdl_status.initialized) {
        SDL_Quit();
    }
}

void mx_sdl_video_init(void) {
    if (_mx_sdl_status.video_initialized) {
        MX_LOG(MX_LOG_ERR, "SDL video subsystem already initalized");
        return;
    }

    if (SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        MX_LOG(MX_LOG_CRIT, SDL_GetError());
        return;
    }

    _mx_sdl_status.video_initialized = true;
}

void mx_sdl_video_shutdown(void) {
    if (_mx_sdl_status.video_initialized) {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

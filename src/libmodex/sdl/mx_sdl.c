#include "core/mx_types.h"
#include "core/mx_log.h"
#include "core/mx_memory.h"

#include "mx_sdl.h"

#include <SDL2/SDL.h>

mx_sdl_t* mx_sdl_create(void) {
    mx_sdl_t* sdl = MX_CALLOC(1, sizeof(mx_sdl_t));
    return mx_sdl_init(sdl);
}

mx_sdl_t* mx_sdl_init(mx_sdl_t *const sdl) {
    if (sdl->initialized) {
        MX_LOG(MX_LOG_ERR, "SDL already initalized");
        return sdl;
    }

    if (SDL_Init(0)) {
        MX_LOG(MX_LOG_CRIT, SDL_GetError());
        return NULL;
    }

    sdl->initialized = true;

    return sdl;
}

void mx_sdl_destroy(mx_sdl_t *const sdl) {
    if (sdl->video_initialized) {
        mx_sdl_video_shutdown(sdl);
    }

    if (sdl->initialized) {
        SDL_Quit();
        sdl->initialized = false;
    }
}

void mx_sdl_free(mx_sdl_t** sdl) {
    mx_sdl_destroy(*sdl);
    MX_FREE(*sdl);
    *sdl = NULL;
}

void mx_sdl_video_init(mx_sdl_t *const sdl) {
    if (sdl->video_initialized) {
        MX_LOG(MX_LOG_ERR, "SDL video subsystem already initalized");
        return;
    }

    if (SDL_InitSubSystem(SDL_INIT_VIDEO)) {
        MX_LOG(MX_LOG_CRIT, SDL_GetError());
        return;
    }

    sdl->video_initialized = true;
}

void mx_sdl_video_shutdown(mx_sdl_t *const sdl) {
    if (sdl->video_initialized) {
        SDL_QuitSubSystem(SDL_INIT_VIDEO);
    }
}

#ifndef H_MXSDL
#define H_MXSDL

#ifndef H_MODEX
#endif

typedef struct {
    bool initialized;
    bool video_initialized;
} mx_sdl_t;

mx_sdl_t* mx_sdl_create(void);
mx_sdl_t* mx_sdl_init(mx_sdl_t *const sdl);
void mx_sdl_destroy(mx_sdl_t *const sdl);
void mx_sdl_free(mx_sdl_t** sdl);

void mx_sdl_video_init(mx_sdl_t *const sdl);
void mx_sdl_video_shutdown(mx_sdl_t *const sdl);

#endif // H_MXSDL

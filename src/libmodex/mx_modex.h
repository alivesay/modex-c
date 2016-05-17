#ifndef H_MXMODEX
#define H_MXMODEX

#ifndef H_MODEX
#include "core/mx_types.h"
#include "core/mx_video.h"
#endif

typedef struct {
    mx_video_t video;
    bool running;
} mx_modex_t;

extern mx_modex_t g_mx_modex;

void mx_modex_boot(void);
void mx_modex_update(void);
void mx_modex_render(void);
void mx_modex_shutdown(void);

#endif // H_MXMODEX

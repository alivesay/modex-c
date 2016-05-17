#include "core/mx_types.h"
#include "core/mx_video.h"

#include "mx_modex.h"

mx_modex_t g_mx_modex = {0};

void mx_modex_boot(void) {
    // TODO: what if this is called twice?
    g_mx_modex.running = false;
    mx_video_create(&g_mx_modex.video);
    g_mx_modex.running = true;
}

void mx_modex_update(void) {
    mx_video_render_begin(&g_mx_modex.video);
}

void mx_modex_render(void) {
    mx_video_render_end(&g_mx_modex.video);
}

void mx_modex_shutdown(void) {
    mx_video_free(&g_mx_modex.video);
}

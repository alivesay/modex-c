#include "modex.h"

#include <unistd.h>

int main() {

    mx_video_mode_t mode = { 320, 240, 8, false };
    mx_log(MX_LOG_INFO, "Booting...");
    
    mx_modex_boot();
    mx_video_mode_set(&g_mx_modex._video, mode);
    //mx_video_view_set();

    for (int i = 0; i < 10; i++) {
        mx_modex_update();
        mx_modex_render();
        sleep(1);
    }

    mx_modex_shutdown();
    return 1;
}

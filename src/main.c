#include "../lib/core/mx_video.h"
#include <unistd.h>

int main() {
   
    mx_video_init();
    mx_video_mode_set(1024, 768, 8, false);
    mx_video_view_set();

    for (int i = 0; i < 60;i++) {
        mx_video_draw_begin();
        mx_video_draw_end();
        sleep(1);
    }

    return 1;
}

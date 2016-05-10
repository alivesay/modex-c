#include "modex.h"

#include <unistd.h>
#include <stdio.h>

int main() {
   
    mx_video_init();
    mx_video_mode_set(320, 240, 8, false);
    mx_video_view_set();

    for (int i = 0; i < 60;i++) {
        mx_video_draw_begin();
        mx_video_draw_end();
        sleep(1);
    }

    return 1;
}

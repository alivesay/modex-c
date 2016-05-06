#include "../lib/mx_video.h"
#include <unistd.h>

int main() {
   
    mx_video_init();
    mx_video_mode_set(512, 384, 8, false);

    for (int i = 0; i < 60;i++) {
        mx_video_draw_begin();
        sleep(1);
    }

    return 1;
}

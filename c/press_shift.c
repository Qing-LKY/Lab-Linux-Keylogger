#include <stdio.h>
#include <string.h>

#include <linux/input.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define N 10000

int str_keyboard(char *s) {
    return \
        (s[0] == 'k' || s[0] == 'K') && s[1] == 'e' && s[2] == 'y' && \
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

int main() {
    char *e_name = get_event_name();
    char path[50];
    sprintf(path, "/dev/input/%s", e_name);
    int fd = open(path, O_WRONLY);
    if(fd < 0) {
        printf("Unable to open %s!\n", path);
        printf("Try to run with `sudo' ?");
        return 1;
    }
    struct input_event ev;
    ev.type = EV_KEY;
    ev.value = 1;
    ev.code = KEY_LEFTSHIFT;
    write(fd, &ev, sizeof(struct input_event));
    close(fd);
    return 0;
}
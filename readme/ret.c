#include <stdio.h>
#include <stdint.h>

int main() {
    int i=0; char buf[44];
    for (i=0;i<=40;i+=4) {
        *(uint32_t *) &buf[i] = 0x400590;
    }
    puts(buf);
    return 0;
}
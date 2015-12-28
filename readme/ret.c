#include <stdio.h>

int main() {
    printf("hallo?");
    int i=0; char buf[44];
    for (i=0;i<=40;i+=4)
    *(long *) &buf[i] = 0x80484cb;
    puts(buf);
}
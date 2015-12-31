#include <stdio.h>

void secret() {
    printf("OH NO, MY SECRET: XxxXXXxxx");
}

void lame (void) {
    char small[30];
    gets (small);
    printf("%s\n", small);
    if(strcmp(small, "foobar") == 0) {
        secret();
    }
}


int main() {
    lame ();
    return 0;
}
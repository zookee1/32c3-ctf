#include <stdio.h>
#include <string.h>


int main() {
    char in[30];
    gets(in);
    if(strcmp(in, "fAJNSODUNFGqo123aas") == 0) {
        printf("SUCCESS\n");
    } else {
        printf("wrong \"%s\"\n", in);
    }
    return 0;
 }
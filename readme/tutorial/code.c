extern void code_start();
extern void code_end();
#include <stdio.h>
void main() { ((void (*)(void)) code_start)(); }
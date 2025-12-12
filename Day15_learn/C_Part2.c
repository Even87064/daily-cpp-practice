#include <stdio.h>
#include <stdlib.h>

int g1;            // BSS
int g2 = 10;       // Data
static int g3;     // BSS
static int g4 = 5; // Data

int main() {
    int x = 1;                 // Stack
    static int s = 2;          // Data
    int *p = malloc(sizeof(int)); // Heap
    *p = 3;

    char *str1 = "abc";        // Read-only (string literal)
    char str2[] = "abc";       // Stack array

    printf("g1 (BSS)        : %p\n", &g1);
    printf("g2 (Data)       : %p\n", &g2);
    printf("g3 (BSS)        : %p\n", &g3);
    printf("g4 (Data)       : %p\n", &g4);

    printf("s  (static)     : %p\n", &s);
    printf("x  (stack)      : %p\n", &x);
    printf("p  (heap ptr)   : %p\n", p);

    printf("str1 literal    : %p\n", str1);
    printf("str2 array      : %p\n", str2);

    free(p);
    return 0;
}

#include <stdio.h>

int main() {
    int a[4] = {10, 20, 30, 40};
    int *p = a;

    printf("a        = %p\n", a);
    printf("&a       = %p\n", &a);
    printf("p        = %p\n", p);
    printf("p+1      = %p\n", p+1);
    printf("&a+1     = %p\n", &a+1);
    printf("*(p+1)   = %d\n", *(p+1));

    return 0;
}

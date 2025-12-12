/*
#include <stdio.h>

int main() {
    int *p = NULL;

    printf("p = %p\n", (void*)p);

    // 故意做錯：解參考 NULL
    *p = 123;

    printf("after write\n");
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    if (!p) return 1;

    printf("p = %p\n", (void*)p);

    *p = 123;
    printf("*p = %d\n", *p);

    free(p);
    return 0;
}

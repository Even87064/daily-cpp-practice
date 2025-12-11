#include <stdio.h>
#include <stdlib.h>   // malloc, free

int main() {
    int *p = malloc(sizeof(int));
    if (p == NULL) {
        printf("malloc 失敗\n");
        return 1;
    }

    *p = 123;
    printf("*p = %d\n", *p);

    free(p);   // 用完要還回去
    return 0;
}
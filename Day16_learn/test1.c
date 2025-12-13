#include <stdio.h>
#include <stdlib.h>

int* alloc_int_array(int n);

int main() {
    int n = 5;
    int *arr = alloc_int_array(n);

    if (!arr) {
        printf("malloc failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        arr[i] = i * 10;
    }

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    free(arr);
    arr = NULL;
    return 0;
}

int* alloc_int_array(int n) {
    int *arr = malloc(sizeof(int) * n);
    if (!arr) return NULL;
    return arr;
}

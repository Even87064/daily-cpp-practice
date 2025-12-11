#include <stdio.h>
#include <stdlib.h>
#include "student.h"

int main() {
    Student arr[5] = {
        {"Ken",   80},
        {"Alice", 95},
        {"Bob",   90},
        {"David", 70},
        {"Eva",   95}
    };

    int n = 5;

    qsort(arr, n, sizeof(Student), compareStudent);

    printf("=== Sorted Students ===\n");
    for (int i = 0; i < n; i++) {
        printf("%s : %d\n", arr[i].name, arr[i].score);
    }

    return 0;
}

// student.c
#include <string.h>
#include "student.h"

int compareStudent(const void* a, const void* b) {
    const Student* A = (const Student*)a;
    const Student* B = (const Student*)b;

    // 1. score 由大到小
    if (A->score != B->score)
        return B->score - A->score;

    // 2. 名字由小到大 (字典順序)
    return strcmp(A->name, B->name);
}

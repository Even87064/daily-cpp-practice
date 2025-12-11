// student.c
#include <stdio.h>
#include "student.h"

void printStudent(const Student* s) {
    printf("%s : %d\n", s->name, s->score);
}

// main.c
#include <string.h>
#include "student.h"

int main() {
    Student s;
    strcpy(s.name, "Alice");
    s.score = 95;
    printStudent(&s);
    return 0;
}

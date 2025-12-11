// student.h
#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[32];
    int score;
} Student;

int compareStudent(const void* a, const void* b);

#endif

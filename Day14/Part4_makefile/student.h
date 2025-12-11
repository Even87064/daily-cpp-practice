// student.h
#ifndef STUDENT_H
#define STUDENT_H

typedef struct {
    char name[32];
    int score;
} Student;

void printStudent(const Student* s);

#endif

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[32];
    int score;
} Student;

int main() {
    Student *s = malloc(sizeof(Student));
    if (!s) {
        printf("malloc 失敗\n");
        return 1;
    }

    strcpy(s->name, "Bob");
    s->score = 80;

    printf("%s : %d\n", s->name, s->score);

    free(s);
    return 0;
}

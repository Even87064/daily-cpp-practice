#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    free(p);
    free(p);   // ❌ double free
    return 0;
}

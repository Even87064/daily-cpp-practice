#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    free(p);
    *p = 10;   // ❌ use-after-free
    return 0;
}

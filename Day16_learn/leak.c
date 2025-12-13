#include <stdlib.h>

int main() {
    int *p = malloc(sizeof(int));
    *p = 10;
    free(p);
    return 0;   // ❌ 忘了 free
}

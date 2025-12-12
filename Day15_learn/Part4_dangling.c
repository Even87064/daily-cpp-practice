#include <stdio.h>

int* bad() {
    int x = 10;        // x 在 stack
    return &x;         // ❌ 回傳區域變數位址（離開 bad() 就死）
}

int main() {
    int *p = bad();

    printf("p = %p\n", (void*)p);
    printf("*p = %d\n", *p);   // ❌ Undefined Behavior：可能印 10、亂數、或 crash

    return 0;
}

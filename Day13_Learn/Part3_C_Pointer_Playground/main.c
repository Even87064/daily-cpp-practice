#include <stdio.h>

int main() {
    char* s1 = "hello";
    char s2[] = "hello";

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    // 測試寫入
    // s1[0] = 'H'; // ❌ 此行會 Crash
    s2[0] = 'H';    // ✔ OK

    printf("modified s2 = %s\n", s2);

    return 0;
}

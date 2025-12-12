# Day15 – C Pointer, Memory Layout, gdb, Makefile

---

## Part 1：C 指標核心（Array / Pointer / String）

### 1. Array 與 Pointer 的本質差異

```c
int a[4] = {10, 20, 30, 40};
int *p = a;
a 的型別是 int[4]

在 expression context 中，a 會 decay 成 int *，等同於 &a[0]

a 不是指標，但常被「當成指標使用」

2. a vs &a
a：指向第一個元素，型別為 int *

&a：指向整個陣列，型別為 int (*)[4]

📌 位址數值可能一樣，但型別完全不同

3. Pointer Assignment
c
複製程式碼
int *p;
p = a;
a 先 decay 成 &a[0]

再指派給 p

沒有 dereference（沒有 *p）

4. Pointer Arithmetic（0x10 題核心）
c
複製程式碼
p + 1
移動 sizeof(int) bytes

指向 a[1]

c
複製程式碼
&a + 1
移動 sizeof(int[4]) bytes

跳過整個陣列

c
複製程式碼
*(p + 1)
等同於 a[1]

📌 Pointer 位移大小由「型別」決定，而不是 base address

5. char *s vs char s[]
c
複製程式碼
char *s1 = "abc";
char s2[] = "abc";
寫法	本質	記憶體位置	是否可寫
char *s1	指標	read-only	❌
char s2[]	陣列	stack	✅

char s[] = "abc" 會建立一份可寫的陣列副本

char *s = "abc" 只是指向 string literal

Part 2：Process Memory Layout
記憶體配置概觀
markdown
複製程式碼
High Address
-----------------
Stack
-----------------
Heap
-----------------
BSS
-----------------
Data
-----------------
Text (Code / String Literal)
-----------------
Low Address
1. Stack
區域變數、函式參數

scope 結束即釋放

不可回傳區域變數位址

2. Heap
malloc / free

生命週期由程式控制

忘記 free 會造成 memory leak

3. Data / BSS
c
複製程式碼
int g1;            // BSS
int g2 = 10;       // Data
static int g3;     // BSS
static int g4 = 5; // Data
global / static 且「未初始化」 → BSS（自動清 0）

有初始化 → Data

4. String Literal
c
複製程式碼
char *s = "abc";
string literal 位於 read-only 區域

嘗試修改 → Undefined Behavior

實驗：印位址驗證 memory segment
c
複製程式碼
printf("&x = %p\n", &x);   // stack
printf("p  = %p\n", p);    // heap
可觀察 stack 與 heap 位址區間差異。

Part 3：gdb 超入門（實際可用）
編譯
bash
複製程式碼
gcc -g test.c -o test
啟動 gdb
bash
複製程式碼
gdb ./test
常用指令
gdb
複製程式碼
b main      // breakpoint
run         // 執行
next        // 下一行
print x     // 看變數
print *p    // 看指標內容
bt          // backtrace
list        // 顯示程式碼
quit        // 離開
📌 next 推進一行，print 定格觀察狀態

Part 4：Pointer Bug Debug
4-1 NULL Dereference
c
複製程式碼
int *p = NULL;
*p = 123;   // SIGSEGV
使用 gdb 定位 crash 行

print p 可確認為 0x0

4-2 Dangling Pointer
c
複製程式碼
int* bad() {
    int x = 10;
    return &x;   // 回傳區域變數位址
}
x 在 stack，離開 scope 後即失效

行為屬於 Undefined Behavior

可能印正常值、亂數、或直接 crash

✅ 正確修法：

回傳值

或回傳 heap（記得 free）

Part 5：Makefile 基礎（實用版）
最小可用 Makefile
makefile
複製程式碼
CC = gcc
CFLAGS = -Wall -g

test: test.c
	$(CC) $(CFLAGS) test.c -o test

clean:
	rm -f test
核心觀念
=：定義變數（不是執行）

$(VAR)：展開變數

變數在同一 Makefile 內可重複使用

command line 變數可覆蓋 Makefile 內設定

bash
複製程式碼
make CFLAGS="-Wall -g"
總結
Pointer 問題的核心在「型別 + 生命週期」

memory layout 決定可寫性與存活時間

gdb 是定位 pointer bug 的基本工具

Makefile 本質是字串展開器，用來管理編譯流程
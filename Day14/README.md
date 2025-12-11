# Day14 – Linux 進階、Makefile、C 動態記憶體

今天整理了五個主題，分別是：  
1. Word Count 程式  
2. Struct 排序（qsort）  
3. Linux 指令進階（grep, find, pipe, xargs）  
4. Makefile 基本練習  
5. C 的 malloc / free 入門

---

## 🟦 Part1 – Word Count

### 功能
讀取一個文字檔，統計每一個單字出現的次數。

### 重點
- 使用 `ifstream` 讀檔  
- 使用 `map<string,int>` 紀錄每個單字次數  
- 遇到大小寫差異可用 `tolower()` 做 normalization  

---

## 🟦 Part2 – Struct Sort（使用 qsort 排序）

### Student 結構
```c
typedef struct {
    char name[32];
    int score;
} Student;
使用 qsort：
c
複製程式碼
int compareStudent(const void *a, const void *b) {
    const Student *A = (const Student*)a;
    const Student *B = (const Student*)b;
    return B->score - A->score;   // 由高到低
}
重點說明
qsort() 需要比較函式

sizeof(Student) 必須正確

Student 的 name 是固定陣列，可以用 strcpy() 指定值

🟦 Part3 – Linux 進階（grep / find / pipe / xargs）
1. grep 常用參數
bash
複製程式碼
grep -n "error" file.txt       # 顯示行號
grep -i "info" file.txt        # 忽略大小寫
grep -E "error|warning" log    # 使用正則 OR
grep -r "TODO" .               # 遞迴搜尋
2. find 常用語法
bash
複製程式碼
find . -name "*.c"             # 找所有 .c 檔
find . -mtime -1               # 最近一天修改的檔案
find . -size +1M               # 大於 1MB 的檔案
3. Pipe（|）
把前一個指令的輸出，丟給下一個指令當輸入。

bash
複製程式碼
ls -l | grep ".c"
4. find + xargs（專案中最實用）
bash
複製程式碼
find . -name "*.c" | xargs grep -n "TODO"
xargs 會把 find 找到的檔案清單傳給 grep。

🟦 Part4 – Makefile 基本練習
Makefile（可編譯 main.c + student.c）
make
複製程式碼
CC = gcc
CFLAGS = -Wall -Wextra -O2

all: main

main: main.o student.o
	$(CC) $(CFLAGS) -o main main.o student.o

main.o: main.c student.h
	$(CC) $(CFLAGS) -c main.c

student.o: student.c student.h
	$(CC) $(CFLAGS) -c student.c

clean:
	rm -f *.o main
重點
-Wall -Wextra → 打開所有警告

-O2 → 程式最佳化

指令前一定要 TAB

改動 .h 時，相關 .o 會重新編譯

🟦 Part5 – C 動態記憶體（malloc / free）
malloc int
c
複製程式碼
int *p = malloc(sizeof(int));
*p = 123;
free(p);
malloc struct
c
複製程式碼
typedef struct {
    char name[32];
    int score;
} Student;

Student *s = malloc(sizeof(Student));
strcpy(s->name, "Bob");   // 將字串複製進可寫的陣列
s->score = 80;

free(s);
重點
"Bob" 是唯讀字串（string literal）

s->name 是陣列 → 可寫

strcpy(dest, src) 第一個參數必須是可寫緩衝區

malloc 一定要對應 free

✔ 今日完成事項
理解 qsort + struct 排序

熟悉 grep / find / pipe / xargs

會寫基礎 Makefile

了解陣列與字串 literal 的差異

學會 malloc/free 的基礎，準備進入 Linked List
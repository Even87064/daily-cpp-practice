Day13 — C Pointer Basics, String Parsing, Linux Commands & Boot Process
📘 今日主題總覽

C++ string parsing 基礎（find / substr）

C pointer：char* vs char[]，指標陣列

Makefile 基本操作（compile / link / clean）

Linux 常用指令（ls / cd / grep / head / tail / pipeline）

Linux Boot Process：從 BIOS → Kernel → User Space

------------------------------------------------------------
🧩 Part 1 — Linux Boot Process（BIOS → Kernel → User Space）
------------------------------------------------------------

Linux 啟動流程概念：

BIOS / UEFI

開機第一階段，初始化硬體、執行自檔案系統讀取 bootloader。

Bootloader（GRUB 等）

負責載入 Linux kernel 到記憶體。

提供不同 kernel / recovery 的啟動選單。

Kernel

掛載 root filesystem。

啟動各種 driver（CPU / RAM / Disk / PCIe / USB / NIC）。

開始系統初始化。

init / systemd

第一個 user-space 程式（PID 1）。

啟動各種服務（networkd, sshd, journald…）。

User Space

登入 Shell → 你才真正進入 Linux 使用者模式。

------------------------------------------------------------
🧩 Part 2 — C++ String Parsing（find / substr）
------------------------------------------------------------
2-1：Split by space（手動分割字串）
vector<string> splitBySpace(const string& s) {
    vector<string> res;
    int pos = 0;

    while (true) {
        int next = s.find(" ", pos);
        if (next == string::npos) {
            res.push_back(s.substr(pos));
            break;
        }
        res.push_back(s.substr(pos, next - pos));
        pos = next + 1;
    }
    return res;
}

2-2：Parse key=value
pair<string, string> parseKeyValue(const string& s) {
    int pos = s.find('=');
    if (pos == string::npos) return {"", ""};

    string first = s.substr(0, pos);
    string second = s.substr(pos + 1);
    return {first, second};
}

------------------------------------------------------------
🧩 Part 3 — C Pointer Basics（char vs char[] & Makefile）*
------------------------------------------------------------
3-1：char* vs char[] 實作
#include <stdio.h>

int main() {
    char* s1 = "hello";   // 字串常量，不能修改
    char  s2[] = "hello"; // 可改內容

    printf("s1 = %s\n", s1);
    printf("s2 = %s\n", s2);

    // s1[0] = 'H';   // ❌ 會 crash（read-only segment）
    s2[0] = 'H';      // ✔ OK

    printf("modified s2 = %s\n", s2);
    return 0;
}

3-2：Makefile（compile / link / clean）
📌 Makefile
all: test

test: main.o
	gcc main.o -o test

main.o: main.c
	gcc -c main.c

clean:
	rm -f *.o test

📌 重點說明

gcc -c main.c → **Compile（編譯）**成 object file：main.o

gcc main.o -o test → **Link（連結）**成執行檔：test

*.o = 所有物件檔（中間產物）

test = 最終執行檔（非 source）

make clean → 清除所有非原始碼，恢復乾淨專案

------------------------------------------------------------
🧩 Part 4 — Linux Commands（ls / cd / grep / head / tail / pipeline）
------------------------------------------------------------
4-1：基礎指令
📌 pwd
pwd


顯示你目前所在的路徑。

📌 ls（常用三個參數即可）
ls
ls -l     # 詳細資訊
ls -a     # 顯示 .git 等隱藏檔
ls -lh    # 人類可讀的檔案大小

📌 cd（cd - 與 cd .. 不是同一回事）
cd ..    # 回到上一層資料夾
cd -     # 回到「前一個」所在位置

4-2：grep（搜尋 log、找行）

找包含 TEMP 的行：

grep TEMP log.txt


找 ERROR：

grep ERROR log.txt


找 CPU 或 FAN：

grep -E "CPU|FAN" log.txt


📌 -E = Extended regex，讓 | 可以代表 OR。

4-3：head / tail（看檔案前/後 N 行）
📌 前 3 行
head -n 3 log.txt

📌 後 5 行
tail -n 5 log.txt

📌 即時追 log（debug daemon 時必用）
tail -f log.txt

4-4：Pipeline（|）資料流操作
📌 把 ls 的結果丟給 grep
ls -l | grep .cpp


流程：
ls 印出的檔案清單 → grep 過濾出 .cpp

📌 找最新的 ERROR（log analysis 常用）
grep ERROR log.txt | tail -n 1


流程：
所有 ERROR 行 → 只取「最後一行」

📌 看最後 5 行中的 TEMP
tail -n 5 log.txt | grep TEMP


流程：
最後 5 行 → 篩 TEMP

📌 三段 pipeline（完整資料流）
cat log.txt | grep TEMP | tail -n 2


流程：
全文 → TEMP 行 → TEMP 的最後兩筆

------------------------------------------------------------
🧩 Part 5 LC 567 – Permutation in String（Sliding Window）
------------------------------------------------------------
bool checkInclusion(string s1, string s2) {
    if (s1.size() > s2.size()) return false;

    vector<int> need(26, 0), window(26, 0);

    for (char c : s1) need[c - 'a']++;

    int k = s1.size();

    // 初始化 window
    for (int i = 0; i < k; i++) {
        window[s2[i] - 'a']++;
    }

    if (window == need) return true;

    // sliding window: i = window右邊界
    for (int i = k; i < s2.size(); i++) {
        window[s2[i] - 'a']++;         // 加入右邊新字元
        window[s2[i - k] - 'a']--;     // 移除左邊舊字元

        if (window == need) return true;
    }

    return false;
}

------------------------------------------------------------
🎉 Today Summary
------------------------------------------------------------

今天學會了：

✅ C++ string parsing（find / substr）
✅ C pointer（char*, char[], array of pointers）
✅ Makefile：compile、link、clean
✅ Linux 常用指令（grep / head / tail / pipeline）
✅ Boot process（BIOS → Kernel → User Space）
🔥 Pipeline 的資料流概念（後續理解 Boost.Process 非常重要）
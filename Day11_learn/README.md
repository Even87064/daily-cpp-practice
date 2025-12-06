# Day11 — Two Pointers（面試）＋ Stack vs Heap（OS 薄層）

## Part A — 演算法：Two Pointers

### 題目：Remove Duplicates from Sorted Array（LC #26）

### 程式碼：
    int removeDuplicates(vector<int>& nums) {
        if (nums.empty()) return 0;

        int i = 0;
        for (int j = 1; j < nums.size(); j++) {
            if (nums[j] != nums[i]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }

### 重點：
- `i` 是慢指標，`j` 是快指標  
- 找到不一樣元素就覆蓋  
- 時間：O(N)  
- 空間：O(1)

---

## Part B — OS：Stack vs Heap（面試常問）

### Stack
- 自動管理（函式呼叫時建立、返回時釋放）  
- 儲存：local variables、return address  
- 容量小但速度快  

### Heap
- 動態配置（new / malloc）  
- 大區域，但較慢  
- 程式員負責釋放  

### 面試重點：
    Stack 是每個 thread 獨立的；
    Heap 是所有 thread 共享的。

---

📌 面試官會問的三題
1️⃣ 「stack vs heap 的差異？」

你回答：

Stack 是 compiler 與 OS 自動管理的小區域，主要儲存 function frame；
Heap 是由程式動態配置的大記憶體區域，由 programmer 管理生命週期。

2️⃣ 「速度差在哪？」

你回答：

Stack 是連續記憶體，由 CPU 做指標偏移即可；
Heap 需要 allocator 處理 free list，因此較慢。

3️⃣ 「thread 與 stack 有什麼關係？」

你回答：

每個 thread 都有獨立的 stack，但共享同一個 heap。

## 小結
- Two pointers 是面試必考題型  
- Stack vs Heap 是 OS 入門必修  
- 適合作為 Linux C++ / BMC 的基礎能力

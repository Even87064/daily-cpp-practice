# Day10 — Sliding Window（面試）＋ Process vs Thread（OS）

## Part A — 演算法：Sliding Window

### 今日目標
- 理解 sliding window 模板  
- C++ 完整實作  
- 完成 LeetCode 最經典題型  

### 題目：Longest Substring Without Repeating Characters

#### 程式碼：
    int lengthOfLongestSubstring(string s) {
        vector<int> count(256, 0);
        int left = 0, maxLen = 0;

        for (int right = 0; right < s.size(); right++) {
            count[s[right]]++;
            while (count[s[right]] > 1) {
                count[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }

### 重點：
- 用 right 擴張窗口  
- 用 left 移除重複字元  
- 時間複雜度 O(N)

---

## Part B — OS：Process vs Thread（面試 100% 會問）

### Process
- heavyweight  
- 擁有獨立記憶體空間  
- context switch 成本高  

### Thread
- lightweight  
- 共享記憶體（heap、global）  
- 各自有 stack  

### 面試：
1.Process（行程）
拥有獨立的虛擬記憶體空間（text/data/heap/stack）
Process 之間記憶體隔離
Context switch 成本高（因為需要切換整個 address space）

2.Thread（執行緒）
位於同一 Process 內，共享相同的虛擬記憶體（heap/global/text）
每個 Thread 自己有獨立的 stack
Context switch 成本低（因為不用切換 address space）
需要注意資料競態（race condition）

Text:程式碼
Data:全域變數、靜態變數
Heap:動態配置（malloc/new）
Stack:function stack frame

Thread 是：
Process 內最小的執行單位
共享 Process 的大部分資源
有自己獨立的 stack、register set
---

## 小結
- Part A 強化面試演算法能力  
- Part B 補 OS 核心觀念（求職必備）  
- 為進入 Linux C++ / BMC 做準備

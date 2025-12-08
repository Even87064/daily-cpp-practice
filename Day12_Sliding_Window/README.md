# Day12 — Sliding Window 基礎 & 三大經典題

## 今日內容總覽
Sliding Window 是處理「連續區間」問題的高效技巧，常見於 Linux C/C++、後端、BMC、面試必考題。

核心概念：  
使用 `left`、`right` 兩個指標在陣列或字串上滑動，避免使用 O(N²) 暴力法。

今日練習三題：

1. **Longest Substring Without Repeating Characters**（可變窗口）
2. **Max Sum Subarray of Size K**（固定窗口）
3. **Minimum Size Subarray Sum（≥ target 的最短子陣列）**（可變窗口）

---

## 1️⃣ Longest Substring Without Repeating Characters

### 概念  
使用 `unordered_map` 記錄字元出現次數。  
若某字元重複 (`freq[c] > 1`)，縮小左邊界直到合法。

---

## 2️⃣ 固定長度 K — Max Sum Subarray of Size K

### 題意  
找出固定長度 `k` 的所有連續子陣列中，**總和最大** 的那一個。

### 解法重點  
- 先計算前 k 個元素 → 第一個窗口  
- 每次右移一格：加入新元素、移除左端舊元素  
- 時間複雜度 O(N)

## 3️⃣ 可變長度 — Minimum Size Subarray Sum（sum ≥ target）

### 題意
找出總和 ≥ target 的最短連續子陣列長度。

### 關鍵觀念
因為陣列元素都是 正整數：
right 擴張 → sum 只會變大
left 收縮 → sum 只會變小
適合以 sliding window 方式用 O(N) 解決所有候選窗口。

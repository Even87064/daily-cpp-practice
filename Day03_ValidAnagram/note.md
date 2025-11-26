# Day03 - Valid Anagram（判斷異位詞）

## 📝 我今天做了什麼
- 寫了 LeetCode 242：Valid Anagram
- 使用 unordered_map<char, int> 做字元計數
- 練習 Hash Table 的 ++ / -- 運作方式
- 理解「字元頻率表」概念

---

## 🧠 題目核心
判斷兩字串是否為異位詞（Anagram），條件如下：
1. 長度相同
2. 字元種類相同
3. 字元出現次數相同  
→ 字元順序不重要

---

## 🔑 Hash Table 解法重點

### 1. 若長度不同 → 直接 false

### 2. 使用 unordered_map<char,int> 作頻率表
    unordered_map<char, int> mp;

### 3. 走訪 s → 每個字元 mp[c]++
    for (char c : s) mp[c]++;

### 4. 走訪 t → 每個字元 mp[c]--
    for (char c : t) mp[c]--;

### 5. 確認所有 value 是否回到 0
    for (auto &p : mp) {
        if (p.second != 0) return false;
    }

---

## ⏱ 時間與空間複雜度
- 時間：O(N)
- 空間：O(1)（字母種類最多固定 26）

---

## 🧪 最終程式碼（縮排 code block，不使用 backticks）
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> mp;

        for (char c : s) mp[c]++;
        for (char c : t) mp[c]--;

        for (auto &p : mp) {
            if (p.second != 0) return false;
        }
        return true;
    }

---

## 💡 今日心得
- mp[c]++ 會自動建立 key
- 互相抵銷技巧（++、--）是 Hash Table 常用手法
- 用 Hash 比排序更快（O(N) vs O(N log N)）

---

## 🎯 明天 Day4 目標
- 練 Valid Parentheses（Stack）
- 開始習慣 STL 的堆疊、佇列操作

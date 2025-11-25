# Day2 - Two Sum + unordered_map

## 我今天做了什麼
- 實作 LeetCode Two Sum（用 C++）
- 使用 unordered_map<int, int> 來記錄「數值 → index」
- 理解 O(n) 的 hash map 解法
- 成功在 WSL 編譯 & 執行 C++ 程式

## Two Sum 解法（我自己的理解）
- 遍歷 nums，每個數字叫 x
- 想要找到 target-x，也就是 need
- 用 mp.count(need) 檢查是否之前看過 need
- 有的話 → 回傳 {mp[need], i}
- 沒的話 → 記錄 mp[x] = i
- 時間複雜度 O(n)，因為每個數字只處理一次

## 我還想再補強的地方
- unordered_map 裡面 count() 做了什麼？
- return {a, b} 這種初始化方式是怎麼工作的？

## 明天的計畫（Day3）
- Valid Parentheses（stack 應用）
- 練習 vector + stack 的使用方式
- 認識 range-based for / auto 的更多細節

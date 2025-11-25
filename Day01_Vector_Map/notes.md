# Day1 - vector & unordered_map

## 我今天做了什麼
- 用 C++ 寫了一個小程式，讀字串 "banana"
- 把每個字元丟進 `vector<char>`
- 用 `unordered_map<char, int>` 統計每個字元出現次數
- 在 WSL + VSCode 裡成功編譯並執行 `./main`

## vector 重點（我現在的理解）
- vector 是：動態陣列，會自己擴充
- 為什麼不用普通 C 陣列：宣告長度需要固定
- `emplace_back()` 在這支程式裡做了什麼：自動擴充動態陣列大小、存值

## unordered_map 重點（我現在的理解）
- unordered_map 是：計算使用次數方便的工具、搜尋值時間複雜度O(1)
- key 是什麼？value 是什麼？（在這支程式裡）:key為字元，表示字串有該element，value則是代表該key所對應的資料，這裡用來當次數統計
- `mp[c]++` 的意思：對該key轉換出來的value進行累加，做一個紀錄次數統計

## 我還有點模糊的地方
auto、reference的概念

## 明天（Day2）要做的事
- 刷 Two Sum（用 unordered_map）
- 練習再寫一個字元統計（換成別的字串）

（Test push from WSL）

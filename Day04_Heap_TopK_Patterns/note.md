# 📘 Day04 — Priority Queue / Heap & Top-K 完全解析

## 🗂️ 今日主題概述
今天學習：
- C++ priority_queue 的基本操作概念
- max-heap 與 min-heap 的差異與用途
- comparator greater<int> 的運作方式
- Top-K 問題的標準解法邏輯
- 使用 min-heap 維持前 K 名元素的策略
- 時間複雜度：O(N log K)
- 空間複雜度：O(K)
---

## 🧠 核心觀念筆記

### 1. Max-Heap 與 Min-Heap
priority_queue 預設是 max-heap，其 top 代表整個堆中最大的元素。  
若改用 greater 作為比較子則會變成 min-heap，top 會變成最小值。

---

### 2. greater<int> 為什麼會得到 min-heap？
greater<int>(a, b) 的比較邏輯是「a > b 時回傳 true」。  
priority_queue 的規則是：比較結果為 true 時，代表 a 的優先權較低。  
因為較大的值會被視為較低優先權，因此會往下沉，導致最小的元素浮到最上面。  
因此使用 greater 時會形成 min-heap。

---

### 3. Top-K 為什麼使用 min-heap？
如果想找「最大 K 個」的元素：

- 使用 min-heap 的原因是最小的元素會浮在 top
- 當堆的大小超過 K 時，可以快速移除最小值
- 最終保留下來的 K 個就是整體最大 K 個元素

max-heap 不適合，因為它的 top 是最大值，無法有效率丟掉「最不重要（最小）」的值。

---

### 4. Top-K 的固定模式
- 找最大 K 個 → 使用 min-heap 維持 K 個元素
- 找最小 K 個 → 使用 max-heap 維持 K 個元素
- 每加入一個新元素，都檢查堆是否超過 K，超過就彈掉優先權最低的那個


---

## 🗒️ 今日自我檢查清單（驗收）
- 我能解釋 greater<int> 為什麼會導致 min-heap
- 我知道 priority_queue 預設是 max-heap
- 我理解 max-heap 與 min-heap 的用途差異
- 我能口述 Top-K 的解法原理
- 我能說明為什麼找最大 K 個要用 min-heap
- 我理解堆的「優先權較低往下沉」這條規則

---

## 📝 心得 / 小結
- 今天了解了greater<int>的底層邏輯
- 目前學習節奏先不求多，但求穩定學習
- 後續會讓自己loading越來越重
- 模板暫時follow AI做出來的，後續會慢慢讓細節都變成手工key-in
---

## 📌 明日預告 / TODO
- 學習 pair 與自訂比較子
- 理解自訂排序與比較規則
- 進入更進階的 heap 題目，如 Kth Largest Element

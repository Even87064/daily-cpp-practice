// word_utils.cpp
#include "word_utils.h"
#include <cctype>    // isalnum, tolower
#include <algorithm> // sort

std::vector<std::string> splitWords(const std::string& s) {
    std::vector<std::string> words;
    std::string cur;

    for (unsigned char ch : s) {  // 用 unsigned char 避免 isalnum UB
        if (std::isalnum(ch)) {
            cur += static_cast<char>(std::tolower(ch));  // 統一轉小寫
        } else {
            if (!cur.empty()) {
                words.push_back(cur);
                cur.clear();
            }
        }
    }

    if (!cur.empty()) {
        words.push_back(cur);
    }

    return words;
}

std::unordered_map<std::string, int>
wordCount(const std::vector<std::string>& lines) {
    std::unordered_map<std::string, int> mp;

    for (const std::string& line : lines) {
        std::vector<std::string> ws = splitWords(line);
        for (const std::string& w : ws) {
            mp[w]++;   // 出現次數累加
        }
    }

    return mp;
}

std::vector<std::pair<std::string, int>>
sortMap(const std::unordered_map<std::string, int>& mp) {
    std::vector<std::pair<std::string, int>> arr(mp.begin(), mp.end());

    std::sort(arr.begin(), arr.end(),
              [](const auto& a, const auto& b) {
                  if (a.second != b.second) {
                      return a.second > b.second; // count 大的在前
                  }
                  return a.first < b.first;       // 字典順序小的在前
              });

    return arr;
}

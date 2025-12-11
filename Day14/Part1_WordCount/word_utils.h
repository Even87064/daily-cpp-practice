// word_utils.h
#ifndef WORD_UTILS_H
#define WORD_UTILS_H

#include <string>
#include <vector>
#include <unordered_map>
#include <utility>

// 將一行字串切成一個個小寫的單字
std::vector<std::string> splitWords(const std::string& s);

// 將多行文字統計成 word -> count
std::unordered_map<std::string, int>
wordCount(const std::vector<std::string>& lines);

// 將 unordered_map 排序後回傳 vector<pair<word, count>>
// 規則：先依照 count 由大到小；count 相同時依字典順序由小到大
std::vector<std::pair<std::string, int>>
sortMap(const std::unordered_map<std::string, int>& mp);

#endif // WORD_UTILS_H

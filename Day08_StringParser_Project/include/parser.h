#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <unordered_map>

// 通用 key=value 字串解析器
// line    : 整行字串，例如 "name=Even, age=23, city=Taipei"
// pairSep : 不同 key/value pair 之間的分隔符，例如 ',' 或 '&'
// kvSep   : key 與 value 的分隔符，通常是 '='
//
// 回傳： unordered_map<string, string>
// 使用方式：
//   auto mp = parse_kv("a=1, b=2", ',', '=');
//   mp["a"] → "1"
std::unordered_map<std::string, std::string>
parse_kv(std::string line, char pairSep = ',', char kvSep = '=');

#endif // PARSER_H

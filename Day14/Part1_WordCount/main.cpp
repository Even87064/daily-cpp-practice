// main.cpp
#include <iostream>
#include <string>
#include <vector>
#include "word_utils.h"

int main() {
    std::vector<std::string> lines;
    std::string line;

    std::cout << "Enter text (Ctrl+D 結束輸入):\n";

    // 讀到 EOF（Ctrl+D）為止
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }

    auto mp = wordCount(lines);
    auto sorted = sortMap(mp);

    std::cout << "\n=== Word Count Result ===\n";
    for (const auto& p : sorted) {
        std::cout << p.first << " : " << p.second << '\n';
    }

    return 0;
}

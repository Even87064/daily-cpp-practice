#include <bits/stdc++.h>
#include "parser.h"

using namespace std;

int main() {
    // 測試 1：逗號分隔
    string line1 = "name=Even, age=23, city=Taipei";
    auto mp1 = parse_kv(line1, ',', '=');

    cout << "=== 測試 1：逗號分隔 ===\n";
    for (auto &p : mp1)
        cout << p.first << " = " << p.second << '\n';
    cout << "city = " << mp1["city"] << "\n\n";

    // 測試 2：& 分隔（URL query 類型）
    string line2 = "id=12&mode=debug&retry=3";
    auto mp2 = parse_kv(line2, '&', '=');

    cout << "=== 測試 2：& 分隔 ===\n";
    for (auto &p : mp2)
        cout << p.first << " = " << p.second << '\n';
    cout << "mode = " << mp2["mode"] << "\n\n";

    // 測試 3：讓使用者輸入一行
    cout << "=== 輸入一行字串（格式：key=value, key=value...）===\n";
    cout << "請輸入：";

    string userLine;
    if (getline(cin, userLine)) {
        auto mp3 = parse_kv(userLine, ',', '=');
        cout << "解析結果：\n";
        for (auto &p : mp3)
            cout << p.first << " = " << p.second << '\n';
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string line = "id=12&mode=debug&retry=3";
    unordered_map<string, string> mp;

    while (!line.empty()) {
        // 1. 找 & 分隔符
        size_t pos = line.find('&');
        string part;

        // 2. 切出本段 part
        if (pos == string::npos) {
            part = line;      // 最後一段
            line = "";        // 沒剩東西了，清空
        } else {
            part = line.substr(0, pos);
            line = line.substr(pos + 1);
        }

        // 3. left trim（保險，雖然通常不會有空白）
        while (!part.empty() && part[0] == ' ')
            part.erase(part.begin());

        // 4. 找 '=' 拆 key / value
        size_t eq = part.find('=');
        if (eq == string::npos) continue; // 無效片段就跳過

        string key = part.substr(0, eq);
        string value = part.substr(eq + 1);

        // 5. 塞 map
        mp[key] = value;
    }

    // 驗證：印出 map 內容
    cout << "解析結果：" << endl;
    for (auto &p : mp) {
        cout << p.first << " = " << p.second << endl;
    }

    // 測試單獨存取
    cout << "\nmode = " << mp["mode"] << endl;

    return 0;
}

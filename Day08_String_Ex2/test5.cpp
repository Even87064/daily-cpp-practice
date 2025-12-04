#include <bits/stdc++.h>
using namespace std;

int main() {
    string line = "name=Even, age=23, city=Taipei";
    unordered_map<string, string> mp;

    while (!line.empty()) {
        // 1. 找逗號
        size_t pos = line.find(',');
        string part;

        // 2. 切段
        if (pos == string::npos) {
            part = line;
            line = "";
        } else {
            part = line.substr(0, pos);
            line = line.substr(pos + 1);
        }

        // 3. left trim
        while (!part.empty() && part[0] == ' ')
            part.erase(part.begin());

        // 4. 拆 key=value
        size_t eq = part.find('=');
        if (eq == string::npos) continue;

        string key = part.substr(0, eq);
        string value = part.substr(eq + 1);

        // 5. 塞進 map
        mp[key] = value;
    }

    // 驗證 map 是否成功
    cout << "解析結果：" << endl;
    for (auto &p : mp)
        cout << p.first << " → " << p.second << endl;

    // 測試存取
    cout << "\n城市是：" << mp["city"] << endl;

    return 0;
}

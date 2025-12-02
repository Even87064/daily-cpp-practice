#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("log2.txt");
    if (!fin.is_open()) {
        cout << "log.txt 無法開啟\n";
        return 1;
    }

    vector<unordered_map<string,string>> data;  // 用來存所有行

    string line;
    while (getline(fin, line)) {
        unordered_map<string,string> mp;  // 每一行的 key-value
        
        istringstream iss(line);
        string token;

        while (iss >> token) {
            int pos = token.find('=');

            if (pos == string::npos) {
                // 沒有 "=" → 異常資料，可忽略或提示
                cout << "[Warning] 不合法 token: " << token << "\n";
                continue;
            }

            string key = token.substr(0, pos);
            string value = token.substr(pos + 1);

            mp[key] = value;
        }

        data.push_back(mp);
    }

    // --- 印出結果 ---
    cout << "=== Log Parse Result ===\n";
    int idx = 1;
    for (auto &mp : data) {
        cout << "[Line " << idx++ << "]\n";
        for (auto &p : mp) {
            cout << p.first << " = " << p.second << "\n";
        }
        cout << "\n";
    }

    return 0;
}

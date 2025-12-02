#include <bits/stdc++.h>
using namespace std;

// --- Part3 的三個功能 ---
void printLinesWithKey(const vector<unordered_map<string,string>> &data,
                       const string &key) {
    int idx = 1;
    for (const auto &mp : data) {
        auto it = mp.find(key);
        if (it != mp.end()) {
            cout << "[Line " << idx << "] " << key << " = " << it->second << "\n";
        }
        idx++;
    }
}

void countStatus(const vector<unordered_map<string,string>> &data) {
    unordered_map<string,int> cnt;

    for (const auto &mp : data) {
        auto it = mp.find("STATUS");
        if (it != mp.end()) {
            string status = it->second;
            cnt[status]++;
        }
    }

    cout << "=== STATUS 統計 ===\n";
    for (const auto &p : cnt) {
        cout << p.first << " : " << p.second << "\n";
    }
}

void printAsJsonLike(const vector<unordered_map<string,string>> &data) {
    cout << "=== JSON-like 輸出 ===\n";
    int idx = 1;
    for (const auto &mp : data) {
        cout << "[Line " << idx++ << "] { ";

        bool first = true;
        for (const auto &p : mp) {
            if (!first) cout << ", ";
            cout << "\"" << p.first << "\": \"" << p.second << "\"";
            first = false;
        }

        cout << " }\n";
    }
}

int main() {
    ifstream fin("log.txt");
    if (!fin.is_open()) {
        cout << "log.txt 無法開啟\n";
        return 1;
    }

    vector<unordered_map<string,string>> data;

    string line;
    while (getline(fin, line)) {
        unordered_map<string,string> mp;
        istringstream iss(line);
        string token;

        while (iss >> token) {
            int pos = token.find('=');
            if (pos == string::npos) {
                cout << "[Warning] 不合法 token: " << token << "\n";
                continue;
            }
            string key = token.substr(0, pos);
            string value = token.substr(pos + 1);
            mp[key] = value;
        }

        data.push_back(mp);
    }

    // --- Part3: 進階操作 ---
    printLinesWithKey(data, "STATUS");
    countStatus(data);
    printAsJsonLike(data);

    return 0;
}

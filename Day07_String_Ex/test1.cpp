#include <bits/stdc++.h>
using namespace std;

int main() {
    ifstream fin("log.txt");
    if (!fin.is_open()) {
        cout << "log.txt 無法開啟\n";
        return 1;
    }

    string line;
    while (getline(fin, line)) {
        unordered_map<string, string> mp; 
        istringstream iss(line);

        string token;
        while (iss >> token) {
            int pos = token.find('=');
            string key = token.substr(0, pos);
            string value = token.substr(pos + 1);
            mp[key] = value;
        }

        // 印出結果
        cout << "---- Parsed ----\n";
        for (auto &p : mp) {
            cout << p.first << " = " << p.second << "\n";
        }
    }

    return 0;
}

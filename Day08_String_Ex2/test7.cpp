#include <bits/stdc++.h>
using namespace std;

unordered_map<string, string> parse_kv(string line,
                                       char pairSep,
                                       char kvSep);

int main() {
    auto mp1 = parse_kv("name=Even, age=23, city=Taipei", ',', '=');
    auto mp2 = parse_kv("id=12&mode=debug&retry=3", '&', '=');

    cout << "=== 測試1 ===\n";
    for (auto &p : mp1)
        cout << p.first << " = " << p.second << endl;

    cout << "\n=== 測試2 ===\n";
    for (auto &p : mp2)
        cout << p.first << " = " << p.second << endl;

    cout << "\n單獨取值：\n";
    cout << "city = " << mp1["city"] << endl;
    cout << "mode = " << mp2["mode"] << endl;

    return 0;
}

unordered_map<string, string> parse_kv(string line,
                                       char pairSep,
                                       char kvSep) 
{
    unordered_map<string, string> mp;

    while (!line.empty()) {
        size_t pos = line.find(pairSep);
        string part;

        if (pos == string::npos) {
            part = line;
            line = "";
        } else {
            part = line.substr(0, pos);
            line = line.substr(pos + 1);
        }

        while (!part.empty() && part[0] == ' ')
            part.erase(part.begin());

        size_t eq = part.find(kvSep);
        if (eq == string::npos) continue;

        string key = part.substr(0, eq);
        string value = part.substr(eq + 1);

        mp[key] = value;
    }

    return mp;
}

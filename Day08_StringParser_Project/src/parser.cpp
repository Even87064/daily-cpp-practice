#include "parser.h"

using namespace std;

unordered_map<string, string>
parse_kv(string line, char pairSep, char kvSep)
{
    unordered_map<string, string> mp;

    while (!line.empty()) {
        // 1. 找 pair 分隔符：例如 ',' 或 '&'
        size_t pos = line.find(pairSep);
        string part;

        if (pos == string::npos) {
            // 沒有分隔符 → 最後一段
            part = line;
            line.clear();
        } else {
            // 切出當前片段，並更新剩下字串
            part = line.substr(0, pos);
            line = line.substr(pos + 1);
        }

        // 2. left trim：去掉前導空白
        while (!part.empty() && part[0] == ' ')
            part.erase(part.begin());

        // 3. 找 '='（或自訂 kvSep）
        size_t eq = part.find(kvSep);
        if (eq == string::npos) continue;

        string key = part.substr(0, eq);
        string value = part.substr(eq + 1);

        // 4. 塞入 hash map
        mp[key] = value;
    }

    return mp;
}

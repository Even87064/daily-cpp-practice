#include <bits/stdc++.h>
using namespace std;

int main() {
    string line = "name=Even, age=23, city=Taipei";

    while (!line.empty()) {
        // Step1：找到逗號
        size_t pos = line.find(',');
        string part;

        // Step2：切出本段 part
        if (pos == string::npos) {
            part = line;      // 最後一段
            line = "";        // 清空避免重複處理
        } else {
            part = line.substr(0, pos);
            line = line.substr(pos + 1);  // 更新為剩下的字串
        }

        // Step3：left trim 去掉前導空白
        while (!part.empty() && part[0] == ' ')
            part.erase(part.begin());

        // Step4：找 '=' 拆 key/value
        size_t eq = part.find('=');
        if (eq == string::npos) {
            cout << "跳過無效段：" << part << endl;
            continue;
        }

        string key = part.substr(0, eq);
        string value = part.substr(eq + 1);

        // Step5：輸出結果
        cout << key << " → " << value << "\n";
    }

    return 0;
}

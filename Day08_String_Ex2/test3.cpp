#include <bits/stdc++.h>
using namespace std;

int main() {
    string part = "   age=23";  // 前面三個空白

    // left trim
    while (!part.empty() && part[0] == ' ')
        part.erase(part.begin());

    cout << "[" << part << "]" << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int main() {
    string part = "name=Even";

    size_t eq = part.find('=');  // 找 '='

    string key = part.substr(0, eq);
    string value = part.substr(eq + 1);

    cout << "key   = " << key << "\n";
    cout << "value = " << value << "\n";

    return 0;
}

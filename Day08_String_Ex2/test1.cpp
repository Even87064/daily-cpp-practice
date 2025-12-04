#include <bits/stdc++.h>
using namespace std;

int main() {
    string s = "name=Even, age=23, city=Taipei";

    size_t pos = s.find(',');   // 找逗號

    string first = s.substr(0, pos);  // 逗號前的字串

    cout << "pos = " << pos << endl;
    cout << "first = " << first << endl;

    return 0;
}

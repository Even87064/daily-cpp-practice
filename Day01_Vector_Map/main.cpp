#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main() {
    string s = "banana";

    vector<char> v;
    for (char c : s) {
        v.push_back(c);
    }

    unordered_map<char, int> mp;
    for (char c : v) {
        mp[c]++;
    }

    cout << "Input string: " << s << "\n";
    cout << "Char counts:\n";
    for (auto &p : mp) {
        cout << p.first << " -> " << p.second << "\n";
    }

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> used(256, -1);
    int left = 0, ans = 0;

    for (int i = 0; i < s.size(); i++) {
        if (used[s[i]] >= left) {
            left = used[s[i]] + 1;
        }
        used[s[i]] = i;
        ans = max(ans, i - left + 1);
    }
    return ans;
}

int main() {
    string s;
    cin >> s;
    cout << lengthOfLongestSubstring(s) << endl;
    return 0;
}

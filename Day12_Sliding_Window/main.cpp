#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    unordered_map<char, int> freq;
    int left = 0;
    int ans = 0;

    for (int right = 0; right < s.size(); right++) {
        char c = s[right];
        freq[c]++;

        // 如果重複了，移動 left 收縮窗口
        while (freq[c] > 1) {
            freq[s[left]]--;
            left++;
        }

        ans = max(ans, right - left + 1);
    }

    return ans;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
    cout << lengthOfLongestSubstring("bbbbb") << endl;     // 1
    cout << lengthOfLongestSubstring("pwwkew") << endl;    // 3
}

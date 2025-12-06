#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(string s) {
    vector<int> count(256,0);
    int left = 0;
    int ans = 0;

    for(int i = 0; i < s.size(); i++){
        count[s[i]]++;
        while(count[s[i]] > 1){
            count[s[left]]--;
            left++;
        }

        if((i- left + 1) > ans){
            ans = i - left + 1;
        }
    }
    return ans;
}

int main() {
    cout << lengthOfLongestSubstring("abcabcbb") << endl; // 3
}

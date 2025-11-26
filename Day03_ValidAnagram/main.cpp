#include <iostream>
#include <unordered_map>
using namespace std;

bool isAnagram(string s, string t) {
    // TODO: Step 1: 如果長度不一樣，直接 return false
    if(s.size() != t.size()){
        return false;
    }

    // TODO: Step 2: 建立一個 unordered_map<char, int> 用來計數字元
    unordered_map<char, int> mp;

    // TODO: Step 3: 走訪 s，對每個字元 mp[c]++
    for(char c:s){
        mp[c]++;
    }

    // TODO: Step 4: 走訪 t，對每個字元 mp[c]--
    for(char c:t){
        mp[c]--;
    }

    // TODO: Step 5: 檢查所有 mp[key] 是否都回到 0
    for(auto it = mp.begin();it != mp.end(); ++it){
        if(it -> second != 0){
            return false;
        }
    }
    return true;
}

int main() {
    string s = "anagram";
    string t = "nagaram";

    cout << boolalpha << isAnagram(s, t) << endl;
    return 0;
}

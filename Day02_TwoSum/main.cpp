#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 回傳兩個 index，使得 nums[i] + nums[j] = target
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> mp; // value -> index

    for (int i = 0; i < (int)nums.size(); i++) {
        int x = nums[i];
        int need = target - x;

        // 如果之前看過 "need" 這個數字，就找到答案了
        if (mp.count(need)) {
            return { mp[need], i };
        }

        // 把目前這個數字紀錄起來：值 -> index
        mp[x] = i;
    }

    // 題目保證一定有解，這裡就回傳空的以防萬一
    return {};
}

int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> ans = twoSum(nums, target);
    if (!ans.empty()) {
        cout << ans[0] << ", " << ans[1] << endl;
    } else {
        cout << "no answer" << endl;
    }

    return 0;
}

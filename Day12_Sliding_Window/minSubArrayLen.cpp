#include <bits/stdc++.h>
using namespace std;

int minSubArrayLen(int target, const vector<int>& nums) {
    int n = nums.size();
    int ans = n+1;
    int tempsum = 0;
    int left = 0;

    for(int i = 0; i < n; i++){
        tempsum += nums[i];
        if(tempsum >= target){
            while((tempsum - nums[left]) >= target){
                tempsum -= nums[left];
                left ++;
            }

            ans = min(ans, i-left+1);
        }
    }
    if(ans == n+1){
        return -1;
    }
    return ans;
}

int main() {
    vector<int> nums = {2, 3, 1, 2, 4, 3};
    int target = 7;
    cout << minSubArrayLen(target, nums) << endl; // 2
}

#include <bits/stdc++.h>
using namespace std;

int maxSumSubarrayOfSizeK(const vector<int>& nums, int k) {
    int n = nums.size(); 
    if (k <= 0 || n < k) return 0;
    
    int tempsum = 0;

    for(int i = 0; i < k; i++){
        tempsum += nums[i];
    }

    int maxans = tempsum;
    
    for(int i = k; i < n; i++){
        tempsum += nums[i];
        tempsum -= nums[i-k];
        maxans = max(maxans, tempsum);
    }

    return maxans;
}

int main() {
    vector<int> nums = {1, 5, 2, 3, 7};
    int k = 3;
    cout << maxSumSubarrayOfSizeK(nums, k) << endl; // 12
}

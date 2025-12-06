#include <bits/stdc++.h>
using namespace std;

int removeDuplicates(vector<int>& nums) {
    if(nums.empty()) 
        return 0;
    int i = 0;
    for(int j = 1; j < nums.size(); j++){
        if(nums[j] != nums[i]){
            i++;
            nums[i] = nums[j];
        }
    }
    return i+1;
}

int main(){
    vector<int> arr = {1,1,2,2,2,3,3,3,3,3};
    cout << removeDuplicates(arr) << endl;
}
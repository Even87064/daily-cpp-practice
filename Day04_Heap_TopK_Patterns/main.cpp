#include <iostream>
#include <vector>
#include <queue>
#include <functional>
using namespace std;

vector<int> topK(vector<int>& nums, int k) {
    priority_queue<int, vector<int>, greater<int>> pq;
    
    for (int x : nums) {
        pq.push(x);
        if (pq.size() > k)
            pq.pop();
    }

    vector<int> ans;
    while (!pq.empty()) {
        ans.push_back(pq.top());
        pq.pop();
    }
    return ans;  // 小到大，沒關係
}

int main() {
    vector<int> nums = {3, 1, 5, 12, 2, 11};
    int k = 3;
    auto res = topK(nums, k);

    cout << "Top " << k << " elements: ";
    for (auto x : res) cout << x << " ";
    cout << endl;
}

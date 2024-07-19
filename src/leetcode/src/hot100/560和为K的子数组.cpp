#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
#include <dbg.h>
using namespace std;

class Solution {
   public:
    int subarraySum(vector<int>& nums, int k) {
        // 有负数的情况，没法用滑动窗口法
        //前缀和？
        // leftSum[j] - leftSum[i] = k
        //  leftSum[i] count(leftSum[i] - k)
        // leftSum[i] = nums[0] + ... +nums[i - 1] 
        vector<int> leftSum(nums.size() + 1, 0);
        for (int i = 1; i < leftSum.size(); i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
        }
        // dbg(leftSum); 
        int ans = 0;
        unordered_map<int, int> map;
        map[0] = 1;
        for (int i = 1; i < leftSum.size(); i++) {
            if (map.count(leftSum[i] - k)) {
                ans += map[leftSum[i] - k];
            }
            map[leftSum[i]] ++; 
        }
        return ans;
    }
};

int main(){
    vector<int>  nums = {6,4,3,1};
    Solution solution;
    cout << solution.subarraySum(nums, 10) << endl;
    return 0;
}
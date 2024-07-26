#include <bits/stdc++.h>
#include <dbg.h>

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxSubArray(vector<int>& nums) {
        // 前缀和
        vector<int> leftSum(nums.size() + 1, 0);
        int min_value = 0;
        int result = INT_MIN;
        for (int i = 1; i <= nums.size(); i++) {
            leftSum[i] = leftSum[i - 1] + nums[i - 1];
            result = max(result, leftSum[i] - min_value);
            min_value = min(leftSum[i], min_value);
        }
        return result;
    }
};
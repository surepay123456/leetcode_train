#include <algorithm>
#include <bits/stdc++.h>

#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:  
    int maxSubArray(vector<int>& nums) {
        //连续子数组的最大和
        //滑动窗口法
        //这里用dp法
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int result = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(nums[i], nums[i] + dp[i - 1]);
            result = max(dp[i], result);
        }
        return result;
    }
};
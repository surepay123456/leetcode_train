#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<int> dp(nums.size(), 0);
        int maxNum = 0;
        // dp[i] 表示以下标i结尾的序列最大乘积和
        // dp[i] = max(nums[i] * dp[i - 1], nums[i]);
        dp[0] = nums[0];
        maxNum = dp[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i] = max(nums[i] * dp[i - 1], nums[i]);
            maxNum = max(maxNum, dp[i]);
        }
        return maxNum;
        //无法处理 [-2 , 3, -4 ]的情况 得二维动态规划
    }
};
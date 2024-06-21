#include <bits/stdc++.h>

#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    int combinationSum4(vector<int>& nums, int target) {
        // 求排列
        // {1, 1, 2}, {1, 2, 1} 就是两个不同的排列
        // 先遍历物品 物品加入的顺序已经给定了 所以求的是组合
        // 要先遍历背包容量
        vector<int> dp(target + 1, 0);
        dp[0] = 1;
        for (int i = 0; i <= target; i++) {
            for (int j = 0; j < nums.size(); j++) {
                if (i >= nums[j] && dp[i] < INT_MAX - dp[i - nums[j]]) {
                    dp[i] += dp[i - nums[j]];
                }
            }
        }

        return dp[target];
    }
};
#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
   public:
    int lengthOfLIS(vector<int>& nums) {
        // dp[i] 表示以i结尾的最长递增子序列的长度
        // 查询当前nums[i] 是否大于等于nums[i  -1]
        // 如果满足则 dp[i] 可以由dp[i - 1]推出
        // dp[i] = max(dp[i  -1 ] + 1, 1 )
        // {10,9,2,5,3,7,101,18}   {2, 5} {2, 3}所以状态转移有误

        // 当前dp[i] 由 dp[0 -> i - 1]来得出!

        int n = nums.size();
        vector<int> dp(n, 1);
        // dp[0] = 1;
        int result = dp[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            result = max(result, dp[i]);
        }

        return result;

    }
};
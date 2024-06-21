#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // 最多可以完成两笔交易
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        // dp[i][0] 表示第一次持有股票
        // dp[i][1] 表示第一次不持有股票
        // dp[i][2] 表示第二次持有股票
        // dp[i][3] 表示第二次不持有股票

        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = -prices[0];
        dp[0][3] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], -prices[i]);
            // 1. 延续上一次持有 2.当天买了一波
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i]);
            // 2. 延续上一次持有 2.当天卖了
            dp[i][2] = max(dp[i - 1][2], dp[i - 1][1] - prices[i]);
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2] + prices[i]);
        }

        return dp[n - 1][3];
    }
};
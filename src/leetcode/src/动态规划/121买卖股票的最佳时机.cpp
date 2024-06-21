#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;
class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // -6 4 -2 3 -2 这不是求最大子序列和么
        // 允许多次买卖就是贪心
        // dp[i] 即在第i天卖出的最大收益
        // dp[0] = 0
        // dp[1] = max(prices[1] - prices[0], 0)
        // dp[i] = max(dp[i - 1], dp[])

        //贪心： 左边最小的

        // int minValue = INT_MAX;
        // int result = 0;
        // for (int i = 0 ; i < prices.size(); i++) {
        //     minValue =  min(minValue, prices[i]);
        //     result = max(result, prices[i] - minValue);
        // }
        // return result;

        // 动态规划版本
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;

        for (int i = 1; i < n; i++) {
            //第i天 持有股票的 票子最大数s
            // i - 1持有; 第i天买入
            dp[i][0] = max(dp[i - 1][0], -prices[i]);

            //第i天 不持有股票的 票子最大数
            // i - 1不持有; 第i天卖出
            dp[i][1] = max(dp[i - 1][1], prices[i] + dp[i][0]);
        }

        return dp[n - 1][1];
    }
};
#include <algorithm>
#include <bits/stdc++.h>

#include <memory>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // // 可以多次购买和抛售
        // // 用贪心计算当天买 第二天卖出的vector
        // int n = prices.size();
        // if (n == 1 || n == 0) {
        //     return 0;
        // }
        // vector<int> porfit(n - 1, 0);
        // for (int i = 0; i < n - 1; i++) {
        //     porfit[i] = prices[i + 1] - prices[i];
        // }
        // int sum = 0;
        // for (auto& i : porfit) {
        //     if (i > 0) {
        //         sum += i;
        //     }
        // }
        // return sum;i

        // 动态规划的算法
        // 动作是当天买入 还是 卖出 还是 持有
        vector<vector<int>> dp(prices.size(), vector<int>(2, 0));
        // dp[i][0] 表示当前持有股票最大的手头金额 
        // 1. 当天买入的  dp[i - 1][1] - prices[i]
        // 2. 昨天的继续持有 dp[i  - 1][0]

        // dp[i][1] 表示当前不持有股票最大的手头金额
        // 1. 当天卖出的 dp[i - 1][0] + prices[i]
        // 2. 昨天的不持有 dp[i][1]
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i  = 1; i < prices.size(); i++) {
            dp[i][0] = max(dp[i - 1][1] - prices[i], dp[i - 1][0]);
            dp[i][1] = max(dp[i - 1][0] + prices[i], dp[i - 1][1]);
        }

        return dp[prices.size() - 1][1];
    }
};
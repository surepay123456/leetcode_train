#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices, int fee) {
        //卖出的步骤 需要一次手续费 代表一次完整的步骤
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        for (int i = 1; i < n; i++) {
            dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - prices[i]);
            dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + prices[i] - fee);
        }
        return dp[n - 1][1];
    }
};
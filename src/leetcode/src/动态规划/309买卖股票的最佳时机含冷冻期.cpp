#include <bits/stdc++.h>
#include <unistd.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(vector<int>& prices) {
        // 不限制交易次数 但是有冷冻期 状态转移有变
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, 0));
        dp[0][0] = -prices[0];
        dp[0][1] = 0;
        dp[0][2] = 0;
        dp[0][3] = 0;

        for (int i = 1; i < n; i++) {
            dp[i][0] =
                max(dp[i - 1][0], max(dp[i - 1][2], dp[i - 1][3]) - prices[i]);
            dp[i][1] = dp[i - 1][0] + prices[i];
            dp[i][2] = dp[i - 1][1];
            dp[i][3] = max(dp[i - 1][3], dp[i - 1][2]);
        }

        return max(dp[n - 1][1], max(dp[n - 1][2], dp[n - 1][3]));
    }
};

int main() {
    vector<int> prices{1, 2, 3, 0, 2};
    Solution solution;
    cout << solution.maxProfit(prices);
    return 0;
}
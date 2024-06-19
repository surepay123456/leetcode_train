#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProfit(int k, vector<int>& prices) {
        //最多完成k次买卖
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2 * k, 0));
        // 偶数下标为持有
        // 奇数下标为不持有
        for (int i = 0; i < 2 * k; i++) {
            if (i % 2 == 0) {
                dp[0][i] = -prices[0];
            } else {
                dp[0][i] = 0;
            }
        }

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < 2 * k; j += 2) {
                dp[i][j] =
                    max(dp[i - 1][j],
                        j > 0 ? dp[i - 1][j - 1] - prices[i] : -prices[i]);
                dp[i][j + 1] = max(dp[i - 1][j + 1], dp[i - 1][j] + prices[i]);
            }
        }

        return dp[n - 1][2 * k - 1];
    }
};
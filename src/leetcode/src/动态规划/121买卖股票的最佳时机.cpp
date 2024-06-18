#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
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
        
        int minValue = INT_MAX;
        int result = 0;
        for (int i = 0 ; i < prices.size(); i++) {
            minValue =  min(minValue, prices[i]);
            result = max(result, prices[i] - minValue);  
        }

        return result;
    }
};
#include <bits/stdc++.h>
#include <iostream>
#include <utility>
#include <vector>

class Solution {
   public:
    int minCostClimbingStairs(vector<int>& cost) {
        // 第i个阶梯可以由第i - 1和 第 i - 2推出
        // dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2])
        int n = cost.size();
        if (n == 1 || n == 0) return 0;
        int dp[n + 1];
        dp[0] = 0;
        dp[1] = 0;
        for (int i = 2; i < n + 1; i++) {
            dp[i] = min(dp[i - 1] + cost[i - 1], dp[i - 2] + cost[i - 2]);
        }
        return dp[n];
    }
};

int main(){
    vector<int> cost{1,100,1,1,1,100,1,1,100,1};
    Solution solution;
    std::cout << solution.minCostClimbingStairs(cost) << std::endl;
    return 0;
}
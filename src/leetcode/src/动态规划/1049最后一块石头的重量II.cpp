#include <bits/stdc++.h>

#include <vector>
using namespace std;
class Solution {
   public:
    int lastStoneWeightII(vector<int>& stones) {
        // 如果sum / 2的背包能够装满 则 最小重量为0
        // 如果装不满，其最大能装下的重量 可以算出碰撞后剩余的最小重量
        int sum = 0;
        int n = stones.size();
        for (int i = 0; i < n; i++) {
            sum += stones[i];
        }
        int bag_weight = sum / 2;
        vector<int> dp(bag_weight + 1, 0);
        for (int i = 0; i < n; i++) {
            for (int j = bag_weight; j >= stones[i]; j--) {
                dp[j] = max(dp[j], dp[j - stones[i]] + stones[i]);
            }
        }
        return sum - dp[bag_weight] - dp[bag_weight];
    }
};
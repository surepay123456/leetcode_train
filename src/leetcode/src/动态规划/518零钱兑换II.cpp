#include <bits/stdc++.h>

#include <vector>

using namespace std;

class Solution {
   public:
    int change(int amount, vector<int>& coins) {
        // coins中每个数都可以重复选取 -> 完全背包问题
        // 如果不能够重复选取呢？ 那就计算amount大小的背包能够被装满
        // 等价于dp[amount] == amount?
        // 或者是装满的方法数
        // 就等价于目标和那个题

        vector<int> dp(amount + 1, 0);
        dp[0] = 1;
        //完全背包在于遍历顺序不同
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                dp[j] = dp[j] + dp[j - coins[i]];
            }
        }
        // 如何理解完全背包的遍历顺序
        // 从前往后遍历的话当前的物品可以反复的加入背包中

        return dp[amount];
    }
};
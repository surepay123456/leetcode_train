#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // A - B = target A + B = sum
        // A = (target + sum) / 2
        // 若 target + sum % 2 != 0 则不存在
        // 接下来就是01背包选择 nums的数 凑成A 有几种方式
        int sum = 0;
        for (int& i : nums) {
            sum += i;
        }
        int bag_weight = (sum + target) / 2;
        if (bag_weight < 0) {
            return 0;
        }
        if ((sum + target) % 2 != 0) return 0;
        vector<int> dp(bag_weight + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = bag_weight; j >= nums[i]; j--) {
                // 现在背包容量为 j, 每个物品的价值为1 最大化当前背包容量的价值

                // 现在背包容量为 j, dp[j]更新为 装i的方法与不装i的方法的总和
                // 那么初始化就很重要了 试想只装第一个物品
                // 背包容量恰好等于这个重量 dp[j] = d[j] + dp[0];
                // dp[0]要弄成1才能有值
                // 如果说有物品重量为0呢 在内层循环里面 dp[0] += dp[0];
                // 就寄了 不装当前0的方法有一种这是欧克的
                // 装当前0的方法可不止dp[0 - 0] == 1 的方法
                // 因为这里0 就可以选择无数次了 变成一个完全背包问题

                // 这两种递推有什么关系？
                // dp[j] = max(dp[j], dp[j - nums[i]] + 1);
                dp[j] += dp[j - nums[i]];
                // dp[j] = dp[j] + dp[j - nums[i]];
            }
        }
        return dp[bag_weight];
    }
};

int main() {
    vector<int> nums = {100};
    int target = -200;
    Solution solution;
    cout << solution.findTargetSumWays(nums, target) << endl;
    return 0;
}
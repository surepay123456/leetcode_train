#include <algorithm>
#include <bits/stdc++.h>

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int coinChange(vector<int>& coins, int amount) {
        // 凑成amount的最小硬币数
        // 硬币可以重复利用

        // [2, 4, 6] 凑4
        // [0, max, max, max, max]
        // [0, max, 1,  max, 2]
        // [0, max, 1,  max, 1]
        // [0, max, 1,  max, 1]
        // 这样子的输出为 1 但是实际无法凑出

        vector<int> dp(amount + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 0; i < coins.size(); i++) {
            for (int j = coins[i]; j <= amount; j++) {
                if(dp[j - coins[i]] == INT_MAX) continue; 
                dp[j] = min(dp[j], dp[j - coins[i]] + 1);
            }
        }
        if(dp[amount] == INT_MAX) return -1;
        return dp[amount];
    }
};

int main(){
    vector<int> coins = {2, 4, 6};
    int amount = 4;
    Solution solution;
    cout << solution.coinChange(coins, amount);
    return 0;
}
#include <algorithm>
#include <bits/stdc++.h>

#include <climits>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int numSquares(int n) {
        // n = 12; 4 + 4 + 4 可以重复使用
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        //最少数量 不存在凑不出的情况, 用1凑
        // 背包容量
        for (int i = 1; i <= n; i++) {
            //遍历物品
            for (int j = 1; j <= n; j++) { 
                if (i >= j * j) {
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
                }
            }
        }
        return dp[n];
    }
};

int main(){
    Solution solution;
    cout << solution.numSquares(13) << endl;
    return 0;
}
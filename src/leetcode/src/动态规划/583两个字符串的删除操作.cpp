#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    int minDistance(string word1, string word2) {
        // dp[i][j] 表示前i 个 与前j 个删除操作最小步数
        /*
            当word1[i] == word2[j] dp[i][j] == dp[i - 1][j - 1]

            当word1[i] != word2[j]
                    删除 i  dp[i - 1][j] + 1
                    删除 j  dp[i][j - 1] + 1
                    两个都删除 dp[i - 1][j - 1] + 2
        */
        vector<vector<int>> dp(word1.size() + 1,
                               vector<int>(word2.size() + 1, 0));
        // 初始化
        for (int i = 0; i <= word1.size(); i++) {
            dp[i][0] = i;
        }
        for (int i = 0; i <= word2.size(); i++) {
            dp[0][i] = i;
        }

        for (int i = 1; i <= word1.size(); i++) {
            for (int j = 1; j <= word2.size(); j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];
                } else {
                    dp[i][j] = min(dp[i - 1][j] + 1,
                                   min(dp[i][j - 1] + 1, dp[i - 1][j - 1] + 2));
                }
            }
        }
        return dp[word1.size()][word2.size()];
    }
};
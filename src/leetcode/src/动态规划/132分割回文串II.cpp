#include <bits/stdc++.h>

#include <climits>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    int minCut(string s) {
        // "aab" 分割一次
        //  dp[i][j] 表示i - j 子串分割为回文串的个数
        //  s[i] == s[j]
        // 没法递推

        vector<vector<bool>> isHuiwen(s.size(), vector<bool>(s.size(), false));

        // isHuiwen[i][j]
        // s[i] == s[j] ?
        //      1. j - i <= 1 isHUiwen[i][j] = true;
        //      2. isHuiwen[i][j] = isHuiwen[i  + 1] [j - 1]

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j <= s.size() - 1; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        isHuiwen[i][j] = true;
                    } else {
                        isHuiwen[i][j] = isHuiwen[i + 1][j - 1];
                    }
                }
            }
        }

        // dp[i] 表示 0 - i子串分割为回文串的个数
        // 当 j -> i是回文串的时候 dp[i] = dp[j] + 1
        vector<int> dp(s.size(), INT_MAX);
        for (int i = 0; i < s.size(); i++) {
            // 0 - i 已经是回文 dp[i] = 0 continue;
            if (isHuiwen[0][i]) {
                dp[i] = 0;
                continue;
            }
            for (int j = 0; j < i; j++) {
                if (isHuiwen[j + 1][i])  // j + 1到 i 是否是回文
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[s.size() - 1];
    }
};

int main() {
    string s("aab");
    Solution solution;
    cout << solution.minCut(s) << endl;
    return 0;
}
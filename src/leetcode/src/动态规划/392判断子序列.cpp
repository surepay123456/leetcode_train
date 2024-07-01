#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool isSubsequence(string s, string t) {
        // // 判断s 是不是t 的子序列
        // // 双指针法
        // int i = 0;
        // int j = 0;
        // while (i < s.size() && j < t.size()) {
        //     if (t[j] == s[i]) {
        //         i++;
        //     }
        //     j++;
        // }
        // if (i == s.size()) {
        //     return true;
        // } else {
        //     return false;
        // }

        //动态规划法
        int m = s.size();
        int n = t.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s[i - 1] == t[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        if (dp[m][n] == m)
            return true;
        else
            return false;
    }
};

int main() {
    string s("axc");
    string t("ahbgdc");
    Solution solution;
    if (solution.isSubsequence(s, t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
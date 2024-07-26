#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
#include <dbg.h>
class Solution {
   public:
    int minFlipsMonoIncr(string s) {
        // 状态机dp
        // 字符0前面的相邻字符一定是0 字符1前面可0可1
        // dp[i][0] 表示当前是0是 翻转s[0 : i]的最小次数
        // dp[i][0] = dp[i - 1][0] + 1 if s[i] == 1
        // dp[i][1] = min(dp[i - 1][1] + 1 if s[i] == 0, dp[i -1][0])
        vector<vector<int>> dp(s.size(), vector<int>(2, 0));
        dp[0][0] = (s[0] == '1' ? 1 : 0);
        dp[0][1] = (s[0] == '0' ? 1 : 0);
        dbg(dp[0][0], dp[0][1]);
        for (int i = 1; i < s.size(); i++) {
            dp[i][0] = dp[i - 1][0] + (s[i] == '1' ? 1 : 0) ;
            // dp[i][0] += s[i] == '1' ? 1 : 0;
            // dbg(dp[i][0]);
            dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + (s[i] == '0' ? 1 : 0);
            // dbg(dp[i][0], dp[i][1]);
        }
        return min(dp[s.size() - 1][0], dp[s.size() - 1][1]);
    }
};

int main() {
    string s = "00110";
    Solution solution;
    cout << solution.minFlipsMonoIncr(s) << endl;
    return 0;
}
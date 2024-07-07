#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int longestPalindromeSubseq(string s) {
        // dp[i][j] i - > j
        // if(s[i] == s[j]) dp[i][j] = dp[i + 1][j - 1]
        vector<vector<int>> dp(s.size(), vector<int>(s.size(), 0));

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = j - i + 1;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1] + 2;
                    }
                } else {
                    if (j - i > 1) {
                        dp[i][j] = max(dp[i + 1][j - 1],
                                       max(dp[i + 1][j], dp[i][j - 1]));
                    } else {
                        dp[i][j] = 1;
                    }
                }
            }
        }

        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = 0; j < s.size(); j++) {
        //         cout << dp[i][j] << " ";
        //     }
        //     cout << endl;
        // }

        return dp[0][s.size() - 1];
    }
};

int main() {
    string s("cbbd");
    Solution solution;
    cout << solution.longestPalindromeSubseq(s) << endl;
    return 0;
}

/*

0  0  1  1  
0  0  0  1  1
0  0  0  0  1

b  b  b  a  b
*/
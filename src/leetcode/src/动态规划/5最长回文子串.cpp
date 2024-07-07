#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    string longestPalindrome(string s) {
        // 子串是连续的
        // s[i] == s[j] dp[i][j] == dp[i + 1][j - 1]
        //  if(dp[i][j] == true) result = max(result, j - i + 1)
        //  result_str = s.substr(i, j - i + 1)
        int result = 0;
        string resStr;
        vector<vector<bool>> dp(s.size(), vector<bool>(s.size(), false));
        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i; j < s.size(); j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 1) {
                        dp[i][j] = true;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                    }
                    if (dp[i][j] == true) {
                        if (result < j - i + 1) {
                            result = j - i + 1;
                            resStr = s.substr(i, result);
                        }
                    }
                } else {
                    dp[i][j] = false;
                }
            }
        }

        // for (int i = 0; i < s.size(); i++) {
        //     for (int j = 0; j < s.size(); j++) {
        //         if (dp[i][j]) {
        //             cout << "t ";
        //         } else {
        //             cout << "f ";
        //         }
        //     }
        //     cout << endl;
        // }

        return resStr;
    }
};

int main() {
    string s("a");
    Solution solution;
    cout << solution.longestPalindrome(s) << endl;
}
/*
1   0   0   0   0
0   1   0   1   0
0   0   1   0   0
0   0   0   1   0
0   0   0   0   1
b   a   b   a   d
*/
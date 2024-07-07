#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int countSubstrings(string s) {
        vector<vector<bool>> dp(s.size() + 1,
                                vector<bool>(s.size() + 1, false));

        int result = 0;
        for (int i = 0; i <= s.size(); i++) {
            dp[i][0] = true;
            dp[s.size()][i] = true;
        }

        for (int i = s.size() - 1; i >= 0; i--) {
            for (int j = i + 1; j <= s.size(); j++) {
                if (s[i] == s[j - 1]) {
                    if (j - 1 - i <= 1) {
                        dp[i][j] = true;
                        result++;
                    } else {
                        dp[i][j] = dp[i + 1][j - 1];
                        if (dp[i][j] == true) {
                            result++;
                        }
                    }
                }
            }
        }
        // for (int i = 0; i < s.size(); i ++) {
        //     for (int j = 1; j <= s.size(); j++) {
        //         if(dp[i][j]){
        //             cout << "t ";
        //         }
        //         else {
        //             cout << "f ";
        //         }
        //     }
        //     cout << endl;
        // }
        return result;
    }
};

int main() {
    string s("aaa");
    Solution solution;
    cout << solution.countSubstrings(s) << endl;
    return 0;
}

/*


    1  t  f  f

    1     t  f

    1        t

    1  1  1  1


    1   t   t   t 

    1       t   t

    1           t

    1   1   1   1
*/
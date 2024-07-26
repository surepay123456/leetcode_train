#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
   public:
    int countHousePlacements(int n) {
        //
        vector<long long> dp(n + 1, 0);
        dp[0] = 1;
        dp[1] = 2;
        long long MOD = 1e9 + 7;
        for (int i = 2; i <= n; i++) {
            dp[i] = (dp[i - 1] + dp[i - 2]) % MOD;
        }
        return (dp[n] * dp[n]) % (MOD);
    }
};
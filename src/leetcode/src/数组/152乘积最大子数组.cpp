#include <bits/stdc++.h>

#include <algorithm>
#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxProduct(vector<int>& nums) {
        vector<vector<double>> dp(nums.size(), vector<double>(2, 0));
        // dp[i][0] 表示以当前i结尾最大，dp[i][1] 表示最小
        dp[0][0] = nums[0];
        dp[0][1] = nums[0];
        double maxResult = INT_MIN;
        maxResult = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            dp[i][0] =
                max((double)nums[i], max((double)nums[i] * dp[i - 1][0],
                                         (double)nums[i] * dp[i - 1][1]));
            dp[i][1] =
                min((double)nums[i], min((double)nums[i] * dp[i - 1][0],
                                         (double)nums[i] * dp[i - 1][1]));
            maxResult = max(maxResult, dp[i][0]);
        }
        return (int)maxResult;
    }
};

// [-2 2, 3, -2, 4]
/*
    -2 -2
    2   -4
    6   -12
    24  -12
    96  -48

*/
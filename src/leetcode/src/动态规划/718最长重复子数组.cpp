#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        //初始化
        int result = 0;
        for (int i = 0; i < m; i++) {
            if (nums1[i] == nums2[0]) {
                dp[i][0] = 1;
                result = 1;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums2[i] == nums1[0]) {
                dp[0][i] = 1;
                result = 1;
            }
        }
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = nums1[i] == nums2[j] ? dp[i - 1][j - 1] + 1 : 0;
                result = max(dp[i][j], result);
            }
        }
        return result;
    }
};
#include <algorithm>
#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
   public:
    int findLengthOfLCIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);
        int result = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                dp[i] = dp[i - 1] + 1;
            }
            result = max(result, dp[i]); 
        }
        return result;
    }
};
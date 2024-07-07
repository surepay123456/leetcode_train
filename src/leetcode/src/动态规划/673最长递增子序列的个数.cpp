#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findNumberOfLIS(vector<int>& nums) {
        // [1, 3, 5, 4, 7]
        vector<int> dp(nums.size(), 1);
        // dp[i] 表示以nums[i] 结尾的递增子串的最大长度
        // if(nums[i] >= nums[i  -1])  dp[i] = dp[i - 1] + 1;
        // 这个递推不阔以 如果小于呢？ 结果怎么推出也

        //
        // count[i] 表示以nums[i] 结尾的最大递增子串的个数
        vector<int> count(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] > nums[j]) {
                    // 重置count
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        count[i] = count[j];
                    }
                    // 更新count
                    else if (dp[j] + 1 == dp[i]) {
                        count[i] += count[j];
                    }
                }
            }
            // cout << dp[i] << " ";
        }
        // cout << endl;
        // for (int i = 0; i < count.size(); i++) {
        //     cout << count[i] << " ";
        // }
        // cout << endl;
        int maxCount = 0;
        int result;
        for (int i = 0; i < dp.size(); i++) {
            if (dp[i] > maxCount) {
                result = count[i];
                maxCount = dp[i];
            } else if (dp[i] == maxCount) {
                result += count[i];
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{1,2,4,3,5,4,7,2};
    Solution solution;
    cout << solution.findNumberOfLIS(nums) << endl;
    return 0;
}
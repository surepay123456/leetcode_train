#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        // nums = [1, 5, 11, 5]
        // sum / 2
        // 如果一个人背包容量为sum / 2 尽可能多装 最终最多装的价值是否为 sum /2
        // 则可以分割等和子集
        int sum = 0;
        int N = nums.size();
        for (int i = 0; i < N; i++) {
            sum += nums[i];
        }
        if (sum % 2 == 1) return false;
        int bag_weight = sum / 2;
        vector<int> dp(bag_weight + 1, 0);
        for (int i = 0; i < N; i++) {
            for (int j = bag_weight; j >= nums[i]; j--) {
                dp[j] = max(dp[j], dp[j - nums[i]] + nums[i]);
            }
        }
        if (dp[bag_weight] == bag_weight)
            return true;
        else
            return false;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 3 ,5};
    if (solution.canPartition(nums)) {
        cout << "yes!" << endl;
    } else {
        cout << "no!" << endl;
    }
    return 0;
}
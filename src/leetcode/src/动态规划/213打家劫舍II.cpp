#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int rob(vector<int>& nums) {
        // 区别是首尾相连了
        // 最后一个num能不能选 取决于第一个和倒数第二个选择否

        if (nums.size() == 1) {
            return nums[0];
        }
        if (nums.size() == 2) {
            return max(nums[0], nums[1]);
        }

        int max1 = robRange(nums, 0, nums.size() - 2);
        int max2 = robRange(nums, 1, nums.size() - 1);

        return max(max1, max2);

        //对于这种首尾有特殊情况 分情况处理
    }

   private:
    int robRange(vector<int>& nums, int start, int end) {
        if (end - start == 0) return nums[start];
        if (end - start == 1) return max(nums[start], nums[end]);
        vector<int> dp(end - start + 1, 0);
        dp[0] = nums[start];
        dp[1] = max(nums[start], nums[start + 1]);
        for (int i = 2; i < end - start + 1; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[start + i]);
        }
        return dp[end - start];
    }
};

int main(){
    vector<int> nums = {1, 2, 3, 1};
    Solution solution;
    cout << solution.rob(nums) << endl;
    return 0;
}
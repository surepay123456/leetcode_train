#include <bits/stdc++.h>
#include <strings.h>

#include <future>
#include <iostream>
#include <vector>

#include "dbg.h"
using namespace std;
class Solution {
   public:
    int firstMissingPositive(vector<int>& nums) {
        // 正整数
        // 记录最小的正数?
        //  如果找到比其小的 如果间隔大于1
        for (int i = 0; i < nums.size(); i++) {
            while (nums[i] != i + 1) {
                if (nums[i] <= 0 || nums[i] > nums.size() || nums[i] == i + 1 ||
                    nums[i] == nums[nums[i] - 1]) {
                    break;
                }
                // [2, 1] -> [1, 2]
                swap(nums[i], nums[nums[i] - 1]);
            }
        }
        // dbg(nums);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != i + 1) {
                return i + 1;
            }
        }
        return nums.size() + 1;
    }
};
int main() {
    vector<int> nums = {1, 1};
    Solution solution;
    cout << solution.firstMissingPositive(nums) << endl;
    return 0;
}
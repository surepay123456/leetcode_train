#include <bits/stdc++.h>
#include <iostream>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // cout << nums << endl;
        // for (int i = 0; i < nums.size(); i++) {
        //     cout << nums[i] << " ";
        // }
        // cout << endl;

        // 双指针法
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            // 剪枝
            if (nums[i] > 0) {
                break;
            }
            
            if (i > 0 && nums[i] == nums[i -1]) {
                continue;
            }

            int left = i + 1;
            int right = nums.size() - 1;
            // 那么如何对 i 进行去重？
            while (left < right) {
                int sum = nums[i] + nums[left] + nums[right];
                if (sum > 0) {
                    right--;
                } else if (sum < 0) {
                    left++;
                } else {
                    results.push_back({nums[i], nums[left], nums[right]});
                    //对left right进行去重
                    while (left < right && nums[left + 1] == nums[left]) {
                        left++;
                    }
                    while (left < right && nums[right - 1] == nums[right]) {
                        right--;
                    }
                    left++;
                    right--;
                }
            }
        }
        return results;
    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    // sorted   -4 -1 -1 0 1 2
    // 不重复的元组 -4 -1 -1 0 1 2 2
    // -
    Solution solution;
    vector<vector<int>> results;
    results = solution.threeSum(nums);
    for (auto &vec : results) {
        for (auto& i : vec) {
            cout << i << " ";
        }
        cout << endl;
    }
    return 0;
}
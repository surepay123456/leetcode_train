#include <algorithm>
#include <cmath>
#include <iostream>
#include <ostream>
#include <unordered_set>
#include <vector>

#include "header.h"

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // cout << nums << endl;
        for (int i = 0; i < nums.size(); i++) {
            cout << nums[i] << endl;
        }

        for (int i = 0; i < nums.size(); i++) {
            // a 的剪枝
            if (nums[i] > 0) break;
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            unordered_set<int>  set;
            for (int j = i+1; j < nums.size()  ; j++) {
                
            }
        }

        //    return nums;
    }
};

int main() {
    vector<int> nums{-1, 0, 1, 2, -1, -4};
    // sorted   -4 -1 -1 0 1 2
    // -
    Solution solution;
    vector<vector<int>> results;
    results = solution.threeSum(nums);
}
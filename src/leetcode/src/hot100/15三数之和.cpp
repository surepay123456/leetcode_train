#include <bits/stdc++.h>
#include <dbg.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        // 和为0
        // dbg(nums);
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            // 对第一个数进行去重
            if (i > 0) {
                while (nums[i] == nums[i - 1] && i < nums.size()) {
                    i++;
                }
                if (i == nums.size()) {
                    break;
                }
            }
            int p = i + 1;
            int q = nums.size() - 1;
            int target = -nums[i];
            while (p < q) {
                // 对p进行去重
                if (p > i + 1) {
                    while (nums[p] == nums[p - 1] && p < q) {
                        p++;
                    }
                }
                if (p == q) {
                    break;
                }
                if (nums[p] + nums[q] > target) {
                    q--;
                } else if (nums[p] + nums[q] < target) {
                    p++;
                } else {
                    ans.push_back({nums[i], nums[p], nums[q]});
                    p++;
                    q--;
                }
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {0, 0, 0, 0};
    Solution solution;
    dbg(solution.threeSum(nums));
    return 0;
}
#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> results;
        for (int i = 0; i < nums.size(); i++) {
            //剪枝 
            if (nums[i] > target && nums[i] > 0) {
                break;
            }
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            for (int j = i + 1; j < nums.size(); j++) {
                //剪枝
                // if (nums[i] + nums[j] > target) {
                //     break;
                // }
                if (nums[i] + nums[j] >= target && nums[j] > 0) {
                    break;
                }
                if (j > i + 1 && j < nums.size() && nums[j] == nums[j - 1]) {
                    continue;
                }
                int left = j + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long long  sum = nums[i] + nums[j] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        results.push_back(vector<int>{nums[i], nums[j],
                                                      nums[left], nums[right]});
                        
                        // 对后面两个数进行降重
                        while (left < right && nums[left] == nums[left + 1]) {
                            left++;
                        }
                        while (left < right && nums[right] == nums[right  -1]) {
                            right--;
                        }
                        left++;
                        right--;
                    }
                }
            }
        }
        return results;
    }
};

int main(){
    vector<int> nums{0,0,0,1000000000,1000000000,1000000000,1000000000};
    Solution solution;
    vector<vector<int>> results = solution.fourSum(nums, 1000000000);
    return 0;
}
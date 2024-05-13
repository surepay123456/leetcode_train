#include "../../include/header.h"
#include <dbg.h>

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int leftIndex = binarySearch(nums, target, true);
        int rightIndex = binarySearch(nums, target, false) - 1;
        if(leftIndex <= rightIndex && rightIndex < nums.size() && nums[leftIndex] == target){
            return vector<int>{leftIndex, rightIndex};
        }

        return vector<int>{-1, -1};
    }

private:
    int binarySearch(vector<int>& nums, int target, bool equal){
        int left = 0, right = nums.size(), ans = right;
        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > target || (equal && nums[mid] >= target)){
                right = mid;
                ans = mid;
            }
            else{
                left = mid + 1;
            }
        }
        return ans;
    }
};

int main() {
    vector<int> nums{ 5,8,8,8,8,10};
    int target = 8;
    Solution solution;
    vector<int> ans = solution.searchRange(nums, target);
    dbg(ans);
    return 0;
}
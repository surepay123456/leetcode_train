#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
   public:
   // >= > <= < 
    int lowerbound(vector<int>& nums, int target){
        int start = 0;
        int end = nums.size() - 1; // [start, end]
        while (start <= end) {
            int mid = start + (end - start) / 2;
            if (nums[mid] >= target) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
        }
        // nums[start] >= target
        return start;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        // target 的开始位置和结束位置
        // 二分查找是查找的位置
        // 二分查找 分别查找左右边界
        int left = lowerbound(nums, target);
        if (left >=  nums.size() || nums[left] != target) {
            return {-1, -1}; 
        } 
        int right = lowerbound(nums, target + 1) - 1;
        return {left, right};
    }
};
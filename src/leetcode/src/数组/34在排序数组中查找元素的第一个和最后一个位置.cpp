#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    vector<int> searchRange(vector<int>& nums, int target) {
        // target 的开始位置和结束位置
        // 二分查找是查找的位置
        // 二分查找 分别查找左右边界
        if (nums.size() == 0) {
            return {-1, -1};
        }
        if (target > nums[nums.size() - 1] || target < nums[0]) {
            return {-1, -1};
        }

        //找到左边界
        int left = 0;
        int right = nums.size() - 1;
        bool isFind = false;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                right = mid - 1;
                isFind = true;
            }
        }
        int leftSide = left;
        if (!isFind) return {-1, -1};

        left = 0;
        right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        int rightSide = right;
        
        return {leftSide, rightSide};
    }
};
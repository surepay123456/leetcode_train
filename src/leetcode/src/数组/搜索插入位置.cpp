#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        //[left, right]
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            else if (nums[mid] > target) {
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }
        // [1, 3, 5, 6]  2 left = 1, right = 0;
        // [1, 3, 5, 6]  7

        return left;

    }
};
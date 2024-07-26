#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
#include <dbg.h>
using namespace std;

class Solution {
   public:
    long long minOperationsToMakeMedianK(vector<int>& nums, int k) {
        // [2, 5, 6, 8, 5] -> [2, 5, 5, 6, 8] 4 >=4 的第一个数 二分
        // [2, 2, 3, 3, 8] 3 <= 4的第一个数 二分 一直到中位数的index累加
        sort(nums.begin(), nums.end());
        dbg(nums);
        int mid = nums.size() / 2;
        if (nums[mid] == k) {
            return 0;
        } else if (nums[mid] > k) {
            long long sum = 0;
            int startIndex = lowerBound(nums, k);
            for (int i = startIndex; i <= mid; i++) {
                sum += nums[i] - k;
            }
            return sum;
        } else {
            long long  sum = 0;
            int startIndex = lowerBound(nums, k) - 1;
            for (int i = startIndex; i >= mid; i--) {
                sum += k - nums[i];
            }
            return sum;
        }
        return 0;
    }

   private:
    int lowerBound(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main() {
    vector<int> nums = {1};
    int k = 1000000;
    Solution solution;
    cout << solution.minOperationsToMakeMedianK(nums, k) << endl;
    return 0;
}
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        //滑动窗口法

        int left = 0;
        int right = 0;
        // [left, right]
        int minLength = INT_MAX;
        int sum = 0;
        while (right <= nums.size()) {
           if (sum < target) {
                sum += nums[right];
                right ++;
           } 
           else {
                minLength = min(minLength, right - left);
                sum -= nums[left];
                left ++;
           }
        }
        return minLength;
    }
};
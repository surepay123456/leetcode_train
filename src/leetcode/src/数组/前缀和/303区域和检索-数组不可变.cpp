#include <bits/stdc++.h>

#include <vector>
using namespace std;

class NumArray {
   public:
    vector<int> frontSum;
    NumArray(vector<int>& nums) {
        // 弄一个前缀和数组
        frontSum.resize(nums.size());
        frontSum[0] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            frontSum[i] = frontSum[i - 1] + nums[i];
        }
    }

    int sumRange(int left, int right) {
        if (left == 0) {
            return frontSum[right];
        } else {
            return frontSum[right] - frontSum[left - 1];
        }
    }
};
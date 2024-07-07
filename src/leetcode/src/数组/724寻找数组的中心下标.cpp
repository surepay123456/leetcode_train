#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        // 左侧和 等于右侧和
        vector<int> leftSum(nums.size(), 0);
        vector<int> rightSum(nums.size(), 0);
        int sum = 0;
        for (int i = 0; i < nums.size(); i ++) {
            leftSum[i] = sum;
            sum += nums[i];
        }
        sum = 0;
        for (int i = nums.size() - 1; i >=0; i --) {
            rightSum[i] = sum;
            sum += nums[i];
        }

        for (int i = 0; i < nums.size(); i ++) {
            if (rightSum[i] == leftSum[i]) {
                return i;
            }
        }
        return -1;

    }
};
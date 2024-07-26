#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    void moveZeroes(vector<int>& nums) {
        // 双指针
        int p = 0;
        int q = 0;
        while (q < nums.size()) {
            if (nums[q] != 0) {
                nums[p] = nums[q];
                p++;
                q++;
            } else {
                q++;
            }
        }
        for (int i = p; p < nums.size(); p++) {
            nums[p] = 0;
        }
    }
};
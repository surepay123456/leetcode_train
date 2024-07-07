#include <bits/stdc++.h>

#include <cstdlib>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> sortedSquares(vector<int>& nums) {
        // p指向头部 q指向尾部
        int p = 0;
        int q = nums.size() - 1;
        vector<int> result(nums.size(), 0);
        int i = nums.size() - 1;
        while (p <= q && i >= 0) {
            if (abs(nums[p]) > abs(nums[q])) {
                nums[i] = nums[p] * nums[p];
                p++;
            } else {
                nums[i] = nums[q] * nums[q];
                q--;
            }
            i--;
        }
        return result;
    }
};
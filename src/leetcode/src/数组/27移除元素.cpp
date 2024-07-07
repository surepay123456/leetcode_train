#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // p指针指向当前要赋值区域， q指针寻找不是val的位置
        int p = 0;
        int q = 0;
        while (q < nums.size()) {
            if(nums[q] != val){
                nums[p] = nums[q];
                p ++;
                q ++;
            }
            else {
                q++;
            }
        }
        return p;
    }
};
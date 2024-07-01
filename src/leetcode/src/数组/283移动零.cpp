#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        // 双指针 一个在数值为0的位置等待赋值， 一个再寻找非0的数
        int low = 0;
        int fast = 0;
        while (fast < nums.size()) {
            if(nums[fast] != 0){
                nums[low] = nums[fast];
                low ++;
                fast++;
            }
            else {
                fast++;
            }
        }
        for (int i = low; i < nums.size(); i ++) {
            nums[i] = 0;
        }
    }
};
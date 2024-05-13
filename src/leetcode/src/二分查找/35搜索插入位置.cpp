#include "../../include/header.h"
#include <dbg.h>

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        // 排序数组
        // 二分区间类型 左闭右开
        int length = nums.size();
        if(!length) return 0;
        int left = 0;
        int right = length;

        while(left < right){
            int mid = (left + right) / 2;
            if(nums[mid] > target){
            right = mid;
            } 
            else if(nums[mid] < target){
                left = mid + 1;
            }
            else {
                return mid;
            }
        }
        // 0 , 5    2  -> 0 , 1  0 -> 1 , 1     
        //  [1, 3]  2     0, 2   1 ->  0, 1  
        return left;
        // [0, length]

    }
};

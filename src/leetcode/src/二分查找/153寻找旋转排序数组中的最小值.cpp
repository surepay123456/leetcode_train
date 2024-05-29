#include "../../include/header.h"
#include <dbg.h>

class Solution {
public:
    int findMin(vector<int>& nums) {

        //找最小的数 
        //还是分有序和无序区间 有序区间非常容易求得最小值
        //每个有序区间进行最小值更新

        int left = 0;
        int right = nums.size() - 1;
        int ans = INT_MAX;
        while(left <= right){
            int mid = (left + right) / 2;
            //[left, mid] 有序
            if(nums[left] <= nums[mid]){
                ans = min(nums[left], ans); 
                //再转到无序区间找最小值
                left = mid + 1; 
            }
            //[mid, right] 有序
            else{
                ans = min(nums[mid], ans);
                right = mid - 1;
            }
        }
        return ans;
    }
};

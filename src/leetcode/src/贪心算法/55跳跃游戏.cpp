#include "../../include/header.h"



class Solution {
public:
    bool canJump(vector<int>& nums) {
        //求一个最大的覆盖范围的问题
        // i -> cover  在循环过程中改变cover
        int cover = 0; //此时只覆盖到了index == 0；
        int n = nums.size();
        if(n == 1) return true;
        for(int i = 0; i <= cover; i++){
            cover = max(cover, i + nums[i]);
            if(cover >= n - 1) return true;
        }
        return false;
    }
};

// //回溯的时间复杂度为  O(n ^ 2)
// class Solution {
// public:
//     bool canJump(vector<int>& nums) {

//         //跳跃的最大长度 求一个覆盖范围 如果覆盖求得覆盖范围包括最后一个元素，则返回true

//         int n = nums.size();
//         // nums[i] + i == n - 1?
//         //覆盖范围多重循环 回溯大法 跳跃路径用下标表示
        
//         pathIndexs.push_back(0);
//         bool result = backtraking(nums, 0, n);
//         return result;
        

//     }

//     vector<int> pathIndexs;

//     bool  backtraking(vector<int>& nums, int start, int n){
//         //查看是否满足条件
//         if((nums[start] + start) >= n - 1){
//             return true;
//         }
//         if(nums[start] == 0) return false;
//         for(int i = 0; i <= nums[start]; i++){ //i 
//             pathIndexs.push_back(i);
//             bool result =  backtraking(nums, start + i, n);
//             if(result) return true;
//             pathIndexs.pop_back();
//         }

//         return false;
//     }
// };
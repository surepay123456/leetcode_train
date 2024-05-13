#include "../../include/header.h"
#include <dbg.h>
class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        //必须要k次取反 贪心策略  转换优先级 负得最多->负数-> 正数小的
        // K 可能大于 n  来回取反噻 0 - > n -1 再从 n - 1 -> 0 计数k次
        // 还是有个问题如果负数全部取正之后， 那么这个策略不行咯 反例[10, 5, 1, 2, 5 ,8] 接下来就要取2反了
        //而且同一个数可以两次取反的嘛 全部都是正数情形[ 1, 2, 3, 4, 5]->[ -1, 2, 3, 4 ,5] 下一步最优是取反-1
        // sort(nums.begin(), nums.end());
        // int n =  nums.size();
        // int i = 0;
        // bool flag;
        // while(i < k){
        //     if(nums[i] < 0) 
        //     {
        //         nums[i] = - nums[i];
        //         i++;
        //     }
        // }

        //要按绝对值大小来排序 从大到下 如果碰到负数则取反 最后反复旋转最后一项

        sort(nums.begin(), nums.end(), absSort);
        // dbg(nums);
        int n = nums.size();
        for(int i = 0; i <= n - 1; i++){
            if(nums[i] < 0 && k > 0){
               nums[i] = - nums[i]; 
               k --;
               dbg(nums);
               
            }
        }
        if(k % 2 == 1) nums[n - 1] = - nums[n - 1];
        dbg(nums);
        int result = 0;
        for(auto i : nums){
            result += i;
        }

        return result;
    }
    
private:
    static bool absSort(int& a, int& b){
        return abs(a) > abs(b) ? true : false; // 如果是大于等于则没法
    }
};

int main(){
    Solution solution;
    vector<int> nums {-17,-20,10,-29,23,5,2,-17,-18,16,6,-21,-2,-17,26,-1,-13,-3,-26,-11,-17,29,-12,30,15,10,27,2,-12,-1};
    int k = 11;
    int result = solution.largestSumAfterKNegations(nums, k);
    return 0;
}
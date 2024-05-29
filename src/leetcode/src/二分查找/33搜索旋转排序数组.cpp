#include "../../include/header.h"
#include <dbg.h>

class Solution {
public:
    int search(vector<int>& nums, int target) {
        //旋转前数组升序
        // 二分的时候 左区间和右区间一定有一个顺序区间，我们只能在顺序区间中找到target
        // 通过不断的二分，一定能保证二分出包括target的顺序区间
        // 二分区间双闭

        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        
        while(left <= right){
            mid = (left + right) / 2;

            if(nums[mid] == target) return mid;

            // 判断左边还是右边是顺序区间 只用mid 和端点值比大小
            // [left, mid] 是顺序区间
            if(nums[mid] >= nums[left]){
                
                //在顺序区间中搜索是否包含target 否则就跑到无序区间去搜索
                if(target >= nums[left] && target <= nums[mid]){
                   right = mid - 1; 
                }
                else{
                    left = mid + 1;
                }
            }
            // [mid, right] 是顺序区间
            else{
                //在顺序区间中搜索是否包含target 否则就跑到无序区间去搜索
                if(target >= nums[mid] && target <= nums[right]){
                   left = mid + 1; 
                }
                else{
                    right = mid - 1;
                }
            }
        }
        return -1;
    }
};

int main(){
    vector<int> nums {3, 1};
    int target = 1;
    Solution solution;
    dbg(solution.search(nums, target));
    return 0;
}
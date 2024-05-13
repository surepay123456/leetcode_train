#include "../../include/header.h"

class Solution {
public:
    int jump(vector<int>& nums) {
        // 用跳跃游戏回溯版本 找到路径之后更新path.size() 但是时间复杂度太高咯

        //下面是|的版本
        //求一个最大的覆盖范围的问题
        // i -> cover  在循环过程中改变cover
        // int cover = 0; //此时只覆盖到了index == 0；
        // int n = nums.size();
        // int jumpTimes = 0;
        // if(n == 1) return true;
        // for(int i = 0; i <= cover; i++){
        //     cover = max(cover, i + nums[i]);
        //     if(cover >= n - 1) return true; // 这里更新数量么 
        // }
        // return false;

        //要以最小的步数来增加覆盖范围  每一步都最大化覆盖范围  如果覆盖到了终点则返回此时的步数
        //如何表示最大化当前步的最大覆盖范围？
        //更新cover即可 如果i + nums[i] > cover时 表示这一步更新了覆盖范围 //怎么表示同属于一步的更新区间呢
        // 用一个变量来表示        i <=maxCoverSameStep 表示同属于一步的 如果大于则就是下一步了 此时 
        //  maxCoverSameStep = cover 
        int cover = 0;
        int maxCoverSameStep = 0;
        int jumptimes = 0;
        int n = nums.size();
        for(int i = 0; i <= cover && i <= n - 1; i++){

            if(i > maxCoverSameStep ){
                jumptimes++; //更新覆盖范围区间了 表示这是下一步了
                maxCoverSameStep = cover;  //更新这一步的最大覆盖区间
            } 

            if(nums[i] + i > cover){
                cover = nums[i] + i;   //更新最大覆盖范围
            }

            if(maxCoverSameStep >= n - 1) return jumptimes;

        }
        return -1;
    }
};
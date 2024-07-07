#include <bits/stdc++.h>

#include <future>
using namespace std;
class Solution {
   public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        // 当nums[i] 是奇数时， i 也是奇数，偶数同理
        // 非负数组 一半奇数一半偶数
        // 额外空间即按个遍历与赋值

        int oddIndex = 1;  // 表示奇数位
        for (int i = 0; i < nums.size(); i += 2) {
            //偶数位上是奇数，找奇数位上是偶数的替换
            if (nums[i] % 2 != 0) {
                while (nums[oddIndex] % 2 == 1 ) {
                    oddIndex += 2;
                }
                swap(nums[i], nums[oddIndex]);
            }
        }
        return nums;
    }
};
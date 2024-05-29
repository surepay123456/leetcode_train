#include <bits/stdc++.h>
#include <dbg.h>

#include <stack>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        // // 循环数组
        // // 左边大于它的数组成的栈
        // // 右边大于它的最近的数
        // // 右边找不到就找左边
        // // {1, 2 ,1} -> {2, -1, 2}

        // // {1, 5, 3, 4, 3}
        // // {1} -1  {5, 1} -1 {5, 1} 5 {5, 1} 5 {5, 1}5
        // // {1, 2, 3 ,4, 1}
        // // {1} -1 {2, 1} -1  {3, 2, 1} -1 {4, 3, 2, 1} -1  {4, 3, 2, 1}  4
        // not 2
        // // {1, 2, 3, 1}
        // // 来回遍历 左右数组
        // int n = nums.size();
        // stack<int> leftGreater;
        // vector<int> leftResult(n);
        // leftGreater.push(nums[0]);
        // leftResult[0] = -1;
        // for (int i = 1; i < n; i++) {
        //     while (!leftGreater.empty()) {
        //         if (nums[i] >= leftGreater.top()) {
        //             leftGreater.pop();
        //         } else {
        //             break;
        //         }
        //     }
        //     if (leftGreater.empty()) {
        //         leftResult[i] = -1;
        //         leftGreater.push(nums[i]);
        //     } else {
        //         leftResult[i] = leftGreater.top();
        //     }
        // }

        // stack<int> rightGreater;
        // vector<int> rightResult(n);
        // rightGreater.push(nums[n - 1]);
        // rightResult[n - 1] = -1;
        // for (int i = n - 1; i >= 0; i--) {
        //     while (!rightGreater.empty()) {
        //         if (nums[i] >= rightGreater.top()) {
        //             rightGreater.pop();
        //         } else {
        //             break;
        //         }
        //     }
        //     if (rightGreater.empty()) {
        //         rightResult[i] = -1;
        //         rightGreater.push(nums[i]);
        //     } else {
        //         rightResult[i] = rightGreater.top();
        //         rightGreater.push(nums[i]);
        //     }
        // }

        // // result from right and left
        // vector<int> result(n);
        // for (int i = 0; i < n; i++) {
        //     if (rightResult[i] != -1) {
        //         result[i] = rightResult[i];
        //     } else if (leftResult[i] != -1) {
        //         result[i] = leftResult[i];
        //     } else {
        //         result[i] = -1;
        //     }
        // }

        // return result;

        // 拼接循环数组
        stack<int> nextGreaterStack;
        int n = nums.size();
        nextGreaterStack.push(nums[n - 1]);
        vector<int> result(2 * n);
        result[2 * n - 1] = -1;
        for (int i = 2 * n - 1; i >= 0; i--) {
            while (!nextGreaterStack.empty()) {
                if (nums[i % n] >= nextGreaterStack.top()) {
                    nextGreaterStack.pop();
                } else {
                    break;
                }
            }

            if (nextGreaterStack.empty()) {
                result[i] = -1;
            } else {
                result[i] = nextGreaterStack.top();
            }
            nextGreaterStack.push(nums[i % n]);
        }
        result.resize(n);
        return result;
    }
};

int main() {
    Solution solution;
    vector<int> nums{1, 2, 1};
    dbg(solution.nextGreaterElements(nums));
    return 0;
}
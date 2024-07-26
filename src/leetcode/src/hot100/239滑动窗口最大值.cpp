#include <bits/stdc++.h>
#include <dbg.h>

#include <deque>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        // 单调队列
        // 滑动窗口定长的情况
        // 新加入的与剔除的关系， 从而不必再每个窗口都算一遍最大值
        /*
         */
        deque<int> que;
        vector<int> ans;
        for (int i = 0; i < k; i++) {
            while (!que.empty() && nums[i] > que.back()) {
                que.pop_back();
            }
            que.push_back(nums[i]);
        }
        // dbg(que);
        ans.push_back(que.front());
        for (int i = k; i < nums.size(); i++) {
            // 去除掉原来的
            if (que.front() == nums[i - k]) {
                que.pop_front();
            }
            //加入新的
            while (!que.empty() && nums[i] > que.back()) {
                que.pop_back();
            }
            que.push_back(nums[i]);
            ans.push_back(que.front());
            // dbg(que);
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {1, 3, -1, -3, 5, 3, 6, 7};
    Solution solution;
    dbg(solution.maxSlidingWindow(nums, 3));
    return 0;
}
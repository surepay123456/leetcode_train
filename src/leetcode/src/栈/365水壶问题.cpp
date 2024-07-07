#include <bits/stdc++.h>

#include <algorithm>
#include <functional>
#include <stack>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
   public:
    bool canMeasureWater(int x, int y, int target) {
        // 使用栈来递归操作，并使用hash边来去除掉重复的状态
        stack<pair<int, int>> stk;
        auto hash_function = [](const pair<int, int>& o) {
            return hash<int>()(o.first) ^ hash<int>()(o.second);
        };
        unordered_set<pair<int, int>, decltype(hash_function)> hashSet(
            0, hash_function);
        stk.emplace(0, 0);
        while (!stk.empty()) {
            // 检查重复
            if (hashSet.count(stk.top())) {
                stk.pop();
                continue;
            }

            hashSet.emplace(stk.top());
            pair<int, int> temp = stk.top();
            int remain_x = temp.first;
            int remain_y = temp.second;

            if (remain_x == target || remain_y == target ||
                remain_x + remain_y == target) {
                return true;
            }

            // 进行多个动作入栈

            // 将 x , y倒满
            stk.emplace(x, remain_y);
            stk.emplace(remain_x, y);

            // 将 x, y倒掉
            stk.emplace(0, remain_y);
            stk.emplace(remain_x, 0);

            // 从x 倒在 y中，  直至y倒满或者x 倒完
            stk.emplace(remain_x - min(remain_x, y - remain_y),
                        remain_y + min(remain_x, y - remain_y));
            stk.emplace(remain_x + min(remain_y, x - remain_x),
                        remain_y - min(remain_y, x - remain_x));
        }
        //检查完了所有的状态 还是没有
        return false;
        // unordered_set<pair<int, int>> hashSet;
    }
};
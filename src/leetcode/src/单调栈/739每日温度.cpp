
#include <bits/stdc++.h>
#include <dbg.h>

#include <new>
#include <stack>
#include <utility>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // [73, 74, 75, 71, 69, 72, 76, 73]
        // [1,   1,  4,  2,  1,  1 , 0 , 0]
        // 从后往前遍历？ 记录最大的温度和其索引
        // 不应该计算最大温度 应该是一个栈 栈是从上到下温度递增的
        // 当新的温度 和栈顶元素相比较 温度比之高 就弹出 再比较下一个栈顶
        // 最后当栈顶大于当前元素 此时存储相应相差结果，
        // 并且将此时的新温度压入栈中
        int num = temperatures.size();
        int maxIndex = num - 1;
        int maxTemp = temperatures[maxIndex];
        stack<pair<int, int>> maxTempStack;
        maxTempStack.push(make_pair(maxTemp, maxIndex));
        vector<int> result(num, 0);

        for (int i = num - 2; i >= 0; i--) {
            while (!maxTempStack.empty()) {
                if (temperatures[i] >= maxTempStack.top().first) {
                    maxTempStack.pop();
                } else {
                    break;
                }
            }
            if (maxTempStack.empty()) {
                result[i] = 0;
                maxTempStack.push(make_pair(temperatures[i], i));
            } else {
                result[i] = maxTempStack.top().second - i;
                maxTempStack.push(make_pair(temperatures[i], i));
            }
        }
        
        return result;
    }
};

int main(){
    Solution solution;
    
    vector<int> temp = {73, 74, 75, 71, 69, 72, 76, 73};
    dbg(solution.dailyTemperatures(temp));
    return 0;
    
}
#include <bits/stdc++.h>

#include <iostream>
#include <stack>
#include <vector>

class Solution {
   public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        // [73, 74, 75, 71, 69, 72, 76, 73]
        // 73 -> 76 -> 76, 72 -> 76, 72, 69 -> 76, 72, 71 -> 76, 75 ->
        // 76, 75, 74 -> 76, 75, 74, 73
        stack<int> temp_stack;
        stack<int> index_stack;
        vector<int> res;
        res.resize(temperatures.size());
        for (int i = int(temperatures.size()) - 1; i >= 0; i--) {
            while (!temp_stack.empty()) {
                if (temp_stack.top() <= temperatures[i]) {
                    temp_stack.pop();
                    index_stack.pop();
                } else {
                    break;
                }
            }
            if (!temp_stack.empty()) {
                res[i] = index_stack.top() - i;
                temp_stack.push(temperatures[i]);
                index_stack.push(i);
            } else {
                res[i] = 0;
                temp_stack.push(temperatures[i]);
                index_stack.push(i);
            }
        }
        return res;
    }
};

int main(){
    Solution solution;
    vector<int> temp{73,74,75,71,69,72,76,73};
    vector<int> res = solution.dailyTemperatures(temp);
    for (auto& i : res) {
        cout << i << " ";
    }
    cout << endl;
    return 0;
}
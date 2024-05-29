#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<string> generateParenthesis(int n) {
        // 有效括号序列 ： 目前序列右括号数量要小于等于左括号序列
        // 总的括号数量小于等于2n
        sum = 2 * n;
        backtracing(0, 0);
        return results;
    }

   private:
    string path;
    vector<string> results;
    int sum;

    void backtracing(int left, int right) {
        if (left > sum / 2) return;
        if (right > sum / 2) return;
        if (left + right > sum) {
            return;
        }
        if (left + right == sum && left == right) {
            results.push_back(path);
            return;
        }
        if (left < right) {
            return;
        }

        // 加左括号
        path.push_back('(');
        backtracing(left + 1, right);
        path.pop_back();

        // 加右括号
        path.push_back(')');
        backtracing(left, right + 1);
        path.pop_back();
    }
};

int main(){
    Solution solution;
    vector<string> results;
    results = solution.generateParenthesis(3);
    for (auto & str : results) {
    cout << str << endl;
    }

    return 0;
}
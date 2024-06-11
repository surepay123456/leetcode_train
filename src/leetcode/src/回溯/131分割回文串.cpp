
#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    vector<vector<string>> partition(string s) {
        backtracing(s, 0);
        return results;
    }

   private:
    vector<string> path;
    vector<vector<string>> results;
    // cutIndex 表示 切割的地方
    // 要避免重复 下一个curIndex 应该大于上一个cutIndex
    // 同时判断此刻切割的 是否是回文串才继续下一步的切割
    void backtracing(string& s, int cutIndex) {
        if (cutIndex == s.size()) {
            results.push_back(path);
        }

        for (int i = cutIndex; i < s.size(); i++) {
            string tempStr = s.substr(cutIndex, i - cutIndex + 1);
            // curindex - > i 是回文串 则继续下一步回溯
            if (isReverse(tempStr)) {
                path.push_back(tempStr);  // 相应回文串
                backtracing(s, i + 1);
                path.pop_back();
            }
        }
    }

    bool isReverse(string s) {
        int n = int(s.size()) - 1;
        int m = 0;
        while (m <= n) {
            if (s[m] != s[n]) {
                return false;
            }
            m++;
            n--;
        }

        return true;
    }
};

int main() {
    string s = "aab";
    Solution solution;
    vector<vector<string>> result = solution.partition(s);
    for (auto& svec : result) {
        for (auto& s : svec) {
            cout << s << " ";
        }
        cout << endl;
    }
}
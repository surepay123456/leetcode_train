#include <bits/stdc++.h>

#include <iostream>
#include <memory>
#include <string>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    bool wordBreak(string s, vector<string>& wordDict) {
        // 问题为 s 是否可以用字典的单词装 字典的单词可以装多次
        // 转换为完全背包的问题
        // dp[i] 表示前i个数可以被字典装
        // dp[j] 能被装的条件是 dp i - j这一段字符在wordDict中
        // 先遍历s
        vector<bool> dp(s.size() + 1, false);
        unordered_set<string> wordSet;
        for (auto& str : wordDict) {
            wordSet.insert(str);
        }
        dp[0] = true;
        for (int i = 0; i <= s.size() + 1; i++) {
            for (int j = 0; j < wordDict.size(); j++) {
                // 当前0 - > i 能装  由 上一次dp[i] 和 当前单词去掉之后的dp[i -
                // size] 包含来确定
                string tempStr;
                if (i >= wordDict[j].size()) {
                    tempStr =
                        s.substr(i - wordDict[j].size(), wordDict[j].size());
                } else {
                    continue;
                }
                //找到这个区间的字符串在set里面
                if (wordSet.find(tempStr) != wordSet.end()) {
                    dp[i] = dp[i] || dp[i - tempStr.size()];
                }
            }
        }
        return dp[s.size()];
    }
};

int main() {
    string s = "leetcode";
    vector<string> wordDict = {"leet", "code"};
    Solution solution;
    if (solution.wordBreak(s, wordDict)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}
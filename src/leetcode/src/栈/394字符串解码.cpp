#include <bits/stdc++.h>

#include <iostream>
#include <mutex>
#include <stack>
#include <string>
#include <utility>

class Solution {
   public:
    string decodeString(string s) {
        // k[encoding_string]
        // 3[a2[c]]
        // multi 3
        // '[' -> stack : 3 " "  res: "" multi:0
        // 'a' -> stack : 3 " "  res: "a" multi:0
        //  '2' -> stack : 3 " " res: "a" multi:2
        // '[' -> stack : 3 " ", 2 "a"   res: "" multi:0
        // 'c' -> stack : 3 " ", 2 "a",  res: "c" mutli:0
        // ']' -> stack : 3 " " res:" acc" multi:0
        // ']' -> stack : { } res:"accaccacc"
        stack<std::pair<int, string>> stk;
        string res;
        string multi = "";
        
        for (char& ch : s) {
            // 数字
            // FIXME: 数字可能是多位的
            if (ch >= '0' && ch <= '9') {
                multi.push_back(ch);
            }
            // 字母
            if (ch >= 'a' && ch <= 'z') {
                res.push_back(ch);
            }
            // 左括号
            if (ch == '[') {
                stk.push(std::make_pair(stoi(multi), res));
                res.clear();
                multi = "";
            }
            // 右括号
            if (ch == ']') {
                std::pair<int, string> temp = stk.top();
                stk.pop();
                string str = "";
                for (int i = 0; i < temp.first; i++) {
                    str += res;
                }
                res = temp.second + str;
            }
        }
        return res;
    }
};

int main() {
    Solution solution;
    std::string res = solution.decodeString("100[leetcode]");
    std::cout << res << std::endl;
    return 0;
}
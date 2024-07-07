#include <bits/stdc++.h>

#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
   public:
    bool backspaceCompare(string s, string t) {
        // "ab#c" "ad#c"
        // 用两个栈来比较
        // 初始化 指针指向末尾
        int i = s.size() - 1;
        int j = t.size() - 1;

        while (1) {
            // 碰到'#'就转换指针到有效位
            int numS = 0;
            int numT = 0;

            while (i >= 0) {
                if (s[i] == '#') {
                    numS++;
                } else {
                    if (numS > 0) {
                        numS--;
                    } else {
                        break;
                    }
                }
                i--;
            }
            while (j >= 0) {
                if (t[j] == '#') {
                    numT++;
                } else {
                    if (numT > 0) {
                        numT--;
                    } else {
                        break;
                    }
                }
                j--;
            }

            if (i < 0 || j < 0) {
                break;
            }
            if (s[i] != t[j]) {
                return false;
            }
            i --;
            j --;
        }
        if (i == -1 && j == -1) {
            return true;
        } else {
            return false;
        }
    }
};

int main() {
    string s = "a#c";
    string t = "c";
    Solution solution;
    if (solution.backspaceCompare(s, t)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}

#include <bits/stdc++.h>

#include <iostream>
#include <scoped_allocator>
#include <string>
using namespace std;

class Solution {
   public:
    bool isLongPressedName(string name, string typed) {
        // 双指针 比较typed是否有name即可
        int i = 0;
        int j = 0;
        while (i < name.size() && j < typed.size()) {
            if (name[i] == typed[j]) {
                i++;
                j++;
            } else {
                // 不相等的情况
                //  1. 检查j 是否与上一个j - 1是一样的 如果是则 j ++,
                //  如果不是则false
                if (j > 0) {
                    if (typed[j] == typed[j - 1]) {
                        j++;
                    } else {
                        return false;
                    }
                }
                // 2. j == 0第一个就匹配不上
                else {
                    return false;
                }
            }
        }
        // 判断 name是否完全匹配
        if (i != name.size()) {
            return false;
        }

        // 判断接下来的j 是不是都一样的
        //  注意j == 1的情况， 即 a 与 a 的配对 此时type.size() == 1不会进入循环
        while (j < typed.size()) {
            if (typed[j] != typed[j - 1]) {
                return false;
            }
            j ++;
        }
        return true;
    }
};

int main() {
    string name = "vtkgn";
    string typed = "vttkgnn";
    Solution solution;
    if (solution.isLongPressedName(name, typed)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
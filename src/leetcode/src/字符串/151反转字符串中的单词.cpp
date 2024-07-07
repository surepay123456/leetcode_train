#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string reverseWords(string s) {
        removeSpace(s);
        reverseWord(s, 0, s.size() - 1);
        int start = 0;
        for (int i = 0; i <= s.size(); i++) {
            if ( i == s.size() || s[i] == ' ') {
                reverseWord(s, start, i - 1);
                start = i + 1;
            }
        }
        return s;
    }

    // 去除多余的空格
    void removeSpace(string& s) {
        //
        int slow = 0;
        for (int i = 0; i < s.size(); i++) {
            // i 指针是 找不是空格的位置 因此 slow <= i
            if (s[i] != ' ') {
                if (slow != 0) {
                    s[slow++] = ' ';
                }
                while (i < s.size() && s[i] != ' ') {
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow);
    }

    void reverseWord(string& s, int start, int end) {
        while (start <= end) {
            swap(s[start++], s[end--]);
        }
    }
};

int main() {
    string s = "  hello world  ";
    Solution solution;
    cout << solution.reverseWords(s) << endl;
    return 0;
}
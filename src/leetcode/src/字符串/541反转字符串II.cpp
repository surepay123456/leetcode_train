#include <bits/stdc++.h>

#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    string reverseStr(string s, int k) {
        // 计数到 2k 反转前k个字符
        int start = 0;
        int i = 0;
        int count = 0;
        while (i < s.size()) {
            i ++;
            count ++;
            if (count == 2 * k) {
                reverseString(s, start, start + k - 1);
                count = 0;
                start = i ;
            }
            if (i == s.size()) {
                if (count >= k & count < 2 * k) {
                    reverseString(s, start, start + k - 1);
                } else if (count < k) {
                    reverseString(s, start, i - 1);
                }
            }
            
        }
        return s;
    }

    void reverseString(string& s, int start, int end) {
        while (start <= end) {
            swap(s[start], s[end]);
            start++;
            end--;
        }
    }
};

int main(){
    string s = "abcdefg";
    Solution solution;
    cout << solution.reverseStr(s, 2) << endl;
    return 0 ; 
}
#include <bits/stdc++.h>
#include <dbg.h>
#include <string>
using namespace std;

class Solution {
   public:
    int minimumPartition(string s, int k) {
        //剪枝
        if (k < 10) {
            for (int i = 0; i < s.size(); i++) {
                if (s[i] - '0' > k) {
                    return -1;
                }
            }
        }

        //滑动窗口 
        int i = 0;
        int j = 0;
        int result = 0;
        while (i < s.size()) {
            if (stoll(s.substr(i, j - i + 1)) <= k && j < s.size()) {
                j ++;
            }
            
            else {
                i = j; 
                result ++;
            }
        }
        return result;
    }
};
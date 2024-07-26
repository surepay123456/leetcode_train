#include <bits/stdc++.h>
#include <dbg.h>

#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
using namespace std;

class Solution {
   public:
    int minSwaps(string s) {
        int n = s.size();
        string s1, s2;
        for (int i = 0; i < n; i ++) {
            if (i % 2) {
                s1.push_back('0');
                s2.push_back('1');
            } else {
                s1.push_back('1');
                s2.push_back('0');
            }
        }
        int countMIN = INT_MAX;
        auto f = [&](string target) {
            if (count(s.begin(), s.end(), '0') !=
                count(target.begin(), target.end(), '0')) {
                return;
            }
            int c = 0;
            for (int i = 0; i < n; i++) {
                if (s[i] == '0' && target[i] == '1') {
                    c++;
                }
            }
            countMIN = min(countMIN, c);
        };
        // dbg(s1);
        f(s1);
        dbg(s2);
        // f(s2);
        return countMIN == INT_MAX ? -1 : countMIN;
    }
};
int main() {
    string s = "010";
    Solution solution;
    cout << solution.minSwaps(s) << endl;
    return 0;
}
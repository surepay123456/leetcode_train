#include <bits/stdc++.h>
#include <dbg.h>

#include <climits>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <dbg.h>
using namespace std;
class Solution {
   public:
    string minWindow(string s, string t) {
        vector<int> targetHash(128, 0);
        vector<int> curHash(128, 0);
        for (int i = 0; i < t.size(); i++) {
            targetHash[t[i]]++;
        }

        int p = 0;
        int start_res = -1;
        int end_res = 0;
        int min_length = INT_MAX;
        for (int q = 0; q < s.size(); q++) {
            curHash[s[q]]++;
            // dbg(s.substr(p, q - p + 1));
            while (isContained(curHash, targetHash)) {
                if (q - p + 1 < min_length) {
                    min_length = q - p + 1;
                    start_res = p;
                    end_res = q;
                }
                curHash[s[p]]--;
                p ++;
                
            }
        }
        return start_res == -1 ? ""
                               : s.substr(start_res, end_res - start_res + 1);
    }

   private:
    bool isContained(vector<int>& a, vector<int>& b) {
        for (int i = 'a'; i < 'z'; i++) {
            if (a[i] < b[i]) {
                return false;
            }
        }
        for (int i = 'A'; i < 'Z'; i++) {
            if (a[i] < b[i]) {
                return false;
            }
        }
        return true;
    }
};
int main(){
    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution solution;
    cout << solution.minWindow(s, t) << endl;
    return 0;
}
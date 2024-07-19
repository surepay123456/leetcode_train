#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <dbg.h>
using namespace std;

class Solution {
   public:
    vector<int> findAnagrams(string s, string p) {
        //窗口匹配到了的时候保存结果 || 窗口长度超出了，进行收缩
        int start = 0;
        int end = 0;
        int n = p.size();
        vector<int> result;
        while (end <= s.size()) {
            if (end - start == n) {
                if (isSame(s.substr(start, end - start), p)) {
                    result.push_back(start);
                }
                start ++;
            }
            else {
                end ++;
            }
        }
        return result;
    }
    bool isSame(string s, string & t){
        if (s.size() != t.size()) {
            return false;
        }
        //字母异位词
        vector<int> hash(26, 0);
        for (int i = 0; i < s.size(); i++) {
            hash[s[i] - 'a'] ++;
            hash[t[i] - 'a'] --;
        }
        for ( int i = 0; i < 26; i++) {
            if (hash[i] != 0) {
                return false;
            }
        }
        return true;
    }
};

int main(){
    string s = "cbaebabacd";
    string t = "abc";
    Solution solution;
    dbg(solution.findAnagrams(s, t));
    return 0;
}
#include <bits/stdc++.h>

#include <iostream>
#include <unordered_set>
#include <dbg.h>
using namespace std;

class Solution {
   public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> hashSet;
        // [p, q)
        int p = 0;
        int q = 0;
        int maxLength = 0;
        int length = 0;
        while (q < s.size()) {
            //加入q
            if (hashSet.count(s[q]) == 0) {
                length++;
                maxLength = max(maxLength, length);
                hashSet.insert(s[q]);
                q++;
                // dbg(hashSet); 
            } else {
                hashSet.erase(s[p]);
                p++;
                length--;
                // dbg(hashSet);
            }
        }
        return maxLength;
    }
};

int main() {
    string s = "abcabcbb";
    Solution solution;
    cout << solution.lengthOfLongestSubstring(s) << endl;
    return 0;
}
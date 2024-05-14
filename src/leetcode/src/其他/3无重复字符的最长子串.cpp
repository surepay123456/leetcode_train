#include "../include/header.h"

class Solution {
public:
    int lengthOfLongestSubstring(string s) {

        int i = 0;
        int j = 0;
        int length = 0;
        unordered_set<char> strset;
        int n = s.size();
        while (j < n)
        {
            while (strset.find(s[j]) != strset.end())
            {
                //说明有重复符号
                strset.erase(s[i]);
                i++;
            }
            strset.insert(s[j]);
            length = max(length, j - i + 1);
            j++;
        }

        return length;
        

    }
};

int main(){
    string str("bbbbb");
    Solution solution; 
    cout << solution.lengthOfLongestSubstring(str) << endl;
    return 0;
}
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        // magazine中的每个字符只能使用一次
        vector<int> hashTable(26, 0);
        for (int i = 0; i < magazine.size(); i++) {
            hashTable[magazine[i] - 'a'] ++;
        }

        for (int i = 0; i < ransomNote.size(); i++) {
            if (hashTable[ransomNote[i] - 'a'] == 0) {
                return false;
            }
            hashTable[ransomNote[i] - 'a'] --;
        }

        return true;
    }
};
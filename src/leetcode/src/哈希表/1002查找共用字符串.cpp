#include <bits/stdc++.h>

#include <algorithm>
#include <cstdint>
#include <string>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<string> commonChars(vector<string>& words) {
        // 找到words里面 相同的字符
        vector<int> hashSet(26, 0);
        // 先查找两个字符串的共用， 依次再加入查找下一个字符串的共用
        for (int i = 0; i < words[0].size(); i++) {
            hashSet[words[0][i] - 'a']++;
        }

        vector<int> hashOtherSet(26, 0);
        for (int i = 1; i < words.size(); i++) {
            // 每次前重置 hashOtherSet
            fill(hashOtherSet.begin(), hashOtherSet.end(), 0);
            for (int j = 0; j < words[i].size(); j++) {
                hashOtherSet[words[i][j] - 'a']++;
            }

            // 取最小值 即保存共用
            for (int k = 0; k < 26; k++) {
                hashSet[k] = min(hashSet[k], hashOtherSet[k]);
            }
        }

        // 最后输出
        vector<string> results;
        for (int i = 0; i < 26; i++) {
            while (hashSet[i] != 0) {
                string s(1, i + 'a');
                results.push_back(s);
                hashSet[i]--;
            }
        }
        return results;
    }
};
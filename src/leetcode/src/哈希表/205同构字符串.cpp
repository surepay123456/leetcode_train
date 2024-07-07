#include <bits/stdc++.h>

#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
   public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char, char> hashMap1;
        unordered_map<char, char> hashMap2;
        for (int i = 0; i < s.size(); i++) {
            // 没有查到这两个字符： 建立映射关系
            // 符合映射关系 continue
            // 不符合映射关系 return false
            if (hashMap1.find(s[i]) == hashMap1.end() &&
                hashMap2.find(t[i]) == hashMap2.end()) {
                hashMap1[s[i]] = t[i];
                hashMap2[t[i]] = s[i];
                continue;
            }
            // 都有映射
            else if (hashMap1.find(s[i]) != hashMap1.end() &&
                     hashMap2.find(t[i]) != hashMap2.end()) {
                if (hashMap1[s[i]] == t[i] && hashMap2[t[i]] == s[i]) {
                    continue;
                } else {
                    return false;
                }
            }
            // 一个有映射 一个没有映射
            else {
                return false;
            }
        }
        return true;
    }
};

int main() {
    string s = "egg";
    string t = "add";
    Solution solution;
    if (solution.isIsomorphic(s, t)) {
        cout << "find !" << endl;
    } else {
        cout << " false " << endl;
    }
    return 0;
}
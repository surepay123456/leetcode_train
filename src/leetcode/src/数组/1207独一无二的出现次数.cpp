#include <bits/stdc++.h>

#include <unordered_map>
#include <unordered_set>
#include <utility>
using namespace std;

class Solution {
   public:
    bool uniqueOccurrences(vector<int>& arr) {
        // 出现次数向量

        unordered_map<int, int> hashNums;
        for (int i = 0; i < arr.size(); i++) {
            if (hashNums.find(arr[i]) != hashNums.end()) {
                hashNums[arr[i]]++;
            } else {
                hashNums.insert(make_pair(arr[i], 1));
            }
        }

        unordered_set<int> hashOccurences;
        for (auto& nums : hashNums) {
            if (hashOccurences.find(nums.second) != hashOccurences.end()) {
                return false;
            } else {
                hashOccurences.insert(nums.second);
            }
        }
        return true;
    }
};
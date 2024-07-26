#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        for (int i = 0; i < nums.size(); i ++) {
            if (hashMap.find(target - nums[i]) != hashMap.end()) {
                return {i, hashMap[target - nums[i]]};
            }
            hashMap.insert(make_pair(nums[i], i));
        }
        return {};
    }
};
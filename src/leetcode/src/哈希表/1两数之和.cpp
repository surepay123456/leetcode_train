#include <bits/stdc++.h>
#include <unordered_map>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> hashMap;
        vector<int> result;
        for ( int i  = 0; i < nums.size(); i++) {
            if (hashMap.find( target - nums[i]) != hashMap.end()) {
                result.push_back(hashMap[target - nums[i]]); 
                result.push_back(i);
                return result;
            }
            hashMap.insert({nums[i], i});
        }
        return {0, 0};
        
    }
};
#include <bits/stdc++.h>
#include <dbg.h>

#include <unordered_set>
using namespace std;
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> hashNum(nums.begin(), nums.end());
        int max_length = 0;
        for (int i = 0; i < nums.size(); i++) {
            // 查询是否有nums[i]  -1
            if (hashNum.count(nums[i] - 1)) {
                continue;
            }
            int length = 1;
            int num = nums[i] + 1;
            while (hashNum.count(num)) {
                length++;
                num++;
            }
            max_length = max(max_length, length);
        }
        return max_length;
    }
};
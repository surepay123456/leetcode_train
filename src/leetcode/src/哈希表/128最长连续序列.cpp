#include <bits/stdc++.h>

#include <unordered_set>
using namespace std;

class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        // [100 4 200 1 3 2]
        unordered_set<int> hashSet(nums.begin(), nums.end());
        int maxResults = 0;
        for (int i = 0; i < nums.size(); i++) {
            int n = 1;
            // 查询是否是开头序列
            if (hashSet.count(nums[i] - 1)) {
                continue;
            }
            int nextNum = nums[i] + 1;
            while (hashSet.count(nextNum)) {
                n++;
                nextNum++;
            }
            maxResults = max(maxResults, n);
        }
        return maxResults;
    }
};
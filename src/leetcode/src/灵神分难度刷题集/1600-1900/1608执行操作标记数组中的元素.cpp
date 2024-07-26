#include <bits/stdc++.h>
#include <dbg.h>

#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<long long> unmarkedSumArray(vector<int>& nums,
                                       vector<vector<int>>& queries) {
        int n = nums.size();
        long long sum = accumulate(nums.begin(), nums.end(), 0);
        vector<int> ids(n);
        iota(ids.begin(), ids.end(), 0);
        stable_sort(ids.begin(), ids.end(),
                    [&](int i, int j) { return nums[i] < nums[j]; });
        dbg(nums, sum, ids);
        vector<long long> ans;
        int index = 0;
        for (int i = 0; i < queries.size(); i++) {
            // 标记index
            if (nums[queries[i][0]]) {
                sum -= nums[queries[i][0]];
                nums[queries[i][0]] = 0;
            }
            dbg(nums);
            // 标记接下来k个最小的元素
            int k = queries[i][1];
            while (index < n && k) {
                // index指向的值下标未被标记
                if (nums[ids[index]]) {
                    sum -= nums[ids[index]];
                    nums[ids[index]] = 0;
                    k--;
                }
                index++;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 1, 2, 3, 1};
    vector<vector<int>> queries = {{1, 2}, {3, 3}, {4, 2}};
    Solution solution;
    dbg(solution.unmarkedSumArray(nums, queries));
    return 0;
}
#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        //先前缀和 找出中点 使得分割的界面两边和是相等的
        sort(nums.begin(), nums.end());
        int n = nums.size();
        vector<long long> sum(n + 1, 0);
        for (int i = 0 ; i < n ; i ++) {
           sum[i + 1] = sum[i] + nums[i]; 
        }

        int m = queries.size();
        vector<long long> ans(m);
        for (int i = 0; i < m; i++) {
            int q = queries[i];
            // 找到 q 在nums
            int j = lowerBound(nums, q) ; // 找到 nums[i] <= q 
            ans[i] = q * j - sum[j];
            ans[i] += sum[nums.size()] - sum[j] -  (nums.size() - j) * q ;
            // j < 0 的情况呢 
        }
        return ans;

    }

    int lowerBound(vector<int>& nums, int target){
        int left = 0;
        int right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] >= target) {
                right = mid -1;
            } 
            else {
                left = mid + 1;
            }
        }
        return left;
    }
};
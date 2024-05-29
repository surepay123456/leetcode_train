#include "../include/header.h"

class Solution
{
public:
    int subarraySum(vector<int> &nums, int k)
    {
        // int i = 0;
        // int j = 0;
        // int n = nums.size();
        // int sum = 0;
        // int ans = 0;

        // int leftnum = 0;
        // // [i, j)  [2,3)
        // while (j <= n - 1)
        // {

        //     leftnum = nums[j]; // FIXME:越界可能
        //     j++;

        //     // 向右扩张
        //     sum += leftnum;

        //     // 判断是否满足要求
        //     // 如果接下来是 全是0的子串
        //     if (sum == k && i != j)
        //         ans++;

        //     // 判断收缩条件，持续收缩到sum <= k 如果leftnum > k 直接收缩到i == j
        //      NOTE: 此题无法判断何时搜索何时扩张， 所以无法用滑动窗口来求解
        //     if (sum > k)
        //     {
        //         while (sum > k && i <= j)
        //         { // i == j 时 不能sum -= nums[i] 因为此时窗口不包含i
        //             if (i != j)
        //             {
        //                 sum -= nums[i];
        //             }
        //             i++;
        //         }
        //         if (sum == k && i != j)
        //         {
        //             ans++;
        //         }
        //     }
        // }

        // return ans;
        unordered_map<int, int> mp;
        mp[0] = 1;
        int ans = 0, pre = 0;
        for(auto& x : nums){
            pre += x;
            if(mp.find(pre - k) != mp.end()){
                ans += mp[pre - k];
            }
            mp[pre]++;
        }

        return ans;
    }
};

int main()
{
    Solution solution;
    vector<int> nums{-1, -1, 1};
    int k = 0;
    cout << solution.subarraySum(nums, k) << endl;
    return 0;
}

// -1  -1,-1 -1,-1,1 
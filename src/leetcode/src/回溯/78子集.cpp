
#include "../../include/header.h"

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {

        size = nums.size();
        backtracking(nums, 0);
        return ans;

    }

private:
    vector<vector<int>> ans;
    vector<int> path;
    int size;

    // int i 指的是[i, nums.size()] 区间
    void backtracking(vector<int>& nums, int start ){

        ans.push_back(path);

        for(int i = start; i <= size; i++){

            path.push_back(nums[i]);
            backtracking(nums, i + 1);
            path.pop_back();

        }

    }

};
#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        // 暴力是O(n ^ 2)
        vector<int> vec = nums;
        sort(vec.begin(), vec.end());
        vector<int>  hash(101, 0);
        for (int i = vec.size() - 1; i >= 0; i--) {
           hash[vec[i]] = i; 
        }
        
        for (int i = 0; i < nums.size(); i ++) {
            vec[i] = hash[nums[i]];
        }

        return vec; 

    }
};

int main(){
    vector<int> nums{8, 1, 2, 2, 3};
    Solution solution;
    vector<int> result = solution.smallerNumbersThanCurrent(nums);
    for (auto & i : result) {
        cout << i << " ";  
    }
    cout << endl;
    return 0;
}
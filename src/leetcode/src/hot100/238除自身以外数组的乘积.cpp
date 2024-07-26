#include <bits/stdc++.h>
#include <dbg.h>

#include <vector>
using namespace std;
class Solution {
   public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left(nums.size(), 0);
        left[0] = 1;
        vector<int> right(nums.size(), 0);
        for (int i = 0; i < left.size(); i++) {
            if (i == 0) {
                left[i] = 1;
            } else {
                left[i] = left[i - 1] * nums[i - 1];
            }
        }
        // dbg(left);
        for (int i = right.size() - 1; i >= 0; i--) {
            if (i == right.size() - 1) {
                right[i] = 1;
            } else {
                right[i] = right[i + 1] * nums[i + 1];
            }
        }
        vector<int> ans(nums.size() , 0);
        for (int i = 0; i < nums.size(); i++) {
            ans[i] = left[i] * right[i];
        }
        return ans;
    }
};
int main() {
    vector<int> nums = {1, 2, 3, 4};
    Solution solution;
    dbg(solution.productExceptSelf(nums));
    return 0;
}
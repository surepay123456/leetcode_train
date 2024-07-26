#include <bits/stdc++.h>
#include <dbg.h>

#include <vector>
using namespace std;

class Solution {
   public:
    void rotate(vector<int>& nums, int k) {
        // [1, 2, 3, 4, 5, 6, 7]
        // [7, 6, 5, 4, 3, 2, 1]
        k = k % nums.size();
        // dbg(k);
        reverse(nums, 0, nums.size() - 1);
        // dbg(nums);

        reverse(nums, 0, k - 1);
        reverse(nums, k, nums.size() - 1);
    }

   private:
    void reverse(vector<int>& nums, int start, int end) {
        while (start < end) {
            swap(nums[start], nums[end]);
            start++;
            end--;
        }
    }
};
int main() {
    vector<int> nums = {1, 2, 3, 4, 5, 6, 7};
    Solution solution;
    solution.rotate(nums, 3);
    return 0;

}
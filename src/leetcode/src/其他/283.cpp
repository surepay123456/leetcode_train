#include "../include/header.h"

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int size = nums.size();
        
        if (size == 0 || size == 1 )
        {
            return;
        }
        
        int i = 0;
        int j = 1;
        
        while (j < size)
        {
        
            if (nums[i] == 0)
            {
                if (nums[j] == 0 )
                {
                    j++; 
                }else{
                    swap(nums[i], nums[j]);
                }
            }
            else{            
                i++;
                j++; 
            }
        }
    }
};

int main() {
    vector<int> nums = {0, 1, 0, 3, 12};
    Solution solution;
    // cout << solution.moveZeroes(nums) << endl; // Use std::cout instead of cout
    solution.moveZeroes(nums);
    // cout << nums << endl;
    for(int num : nums){
        cout << num << endl;
    }
    return 0;
}
#include "../include/header.h"
// #include <unordered_set> // Include the necessary header file for unordered_set
using namespace std;
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> num_set;

        int longest_list = 0;

        for(int num : nums){
            num_set.emplace(num);
        }        


        for(int num : nums){
            if(num_set.find(num - 1) != num_set.end()){
                continue;
            }
            
            int temp_num_list = 1;
            int num_temp = num;
            while (num_set.find(num_temp + 1) != num_set.end())
            {
                temp_num_list ++;
                num_temp = num_temp + 1;
                /* code */
            }

            longest_list = max(longest_list, temp_num_list);
            
        }

        return longest_list;
    }
};

// #include <iostream> // Include the necessary header file for input/output operations in C++

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution solution;
    cout << solution.longestConsecutive(nums) << endl; // Use std::cout instead of cout
    return 0;
}
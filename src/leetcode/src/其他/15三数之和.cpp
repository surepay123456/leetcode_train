#include "../include/header.h"

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       sort(nums.begin(), nums.end());
       
       vector<vector<int>>  ans;

       vector<vector<int>>  twosum_ans;
       
       int n = nums.size();

       if(n < 3) return vector<vector<int>> {};
       
       for(int i = 0; i <= n - 3; i++){

            // //第一个元素去重 在调用两数之和之前是因为[1，1，1，2，3]  会出现[1, 1, 2] 这种情况 先去重 i直接等于2 就不会出现两数之和中有个数和 nums[i]相同
            // while(nums[i] == nums[i + 1] && (i + 1 <= n - 3)){ 
            //     i++;
            // }
            //调用两数之和的方法 得到接下来序列的目标值
            twosum_ans = twoSum(nums, i + 1, -nums[i]);
            if (!twosum_ans.empty())
            {
                for ( auto &vec : twosum_ans){
                    
                    vec.push_back(nums[i]);
                    ans.push_back(vec);
                }
            }
            //保证第一个元素不重复
            while(nums[i] == nums[i + 1] && (i + 1 <= n - 3)){ 
                i++;
            }
            
       }
       return ans;
       
        
    }

    vector<vector<int>> twoSum(vector<int>& nums, int begin, int val){
        
        int n = nums.size() - begin; 

        if (n == 0 || n == 1) return vector<vector<int>> {};
        
        
        int i = begin;
        int j = nums.size() - 1 ;
        
        vector<vector<int>> ans;
        
        while (i < j)
        {
            int left = nums[i];
            int right = nums[j];

            if(left + right < val){
                // while (nums[i] == nums[i + 1] && i < j) //需要满足条件 i < j 保证索引不越界
                // {
                //     i++;
                // }
                i++; // 若此时 i == j 且 j 是 n - 1 则 num[i + 1]就会越界错误 若加上 i < j 则不会索引nums[i+1]
                while (nums[i] == left && i < j ) i++; 
            }
            else if(left + right  > val){ 
                // while (nums[j] == nums[j - 1] && i < j)
                // {
                //     j--;
                // }   
                j--;
                while (nums[j] == right && i < j ) j--; 
            }
            else{
                // while ( nums[i] == nums[i + 1] || nums[j] == nums[j - 1] && i < j)
                // {
                //     i++;
                //     j--;
                // }
                ans.push_back(vector<int> {nums[i], nums[j]});    
                while (nums[i] == left && i < j ) i++; 
                while (nums[j] == right && i < j ) j--; 
            }
        }
        
        return ans;
    }
};

int main(){

    vector<int> nums;
    Solution solution;
    vector<vector<int>> ans;
    // nums =  vector<int> {1, 2, 2, 3, 3 ,4};
    // nums =  vector<int> {-1 ,0, 1, 2, -1, -4};
    nums =  vector<int> {0, 0, 0};
    int target = 0;
    // ans = solution.twoSum(nums, 0, target);
    ans = solution.threeSum(nums);
    for(auto & vec : ans){
        for(auto & num : vec){
            cout << num << endl;
        }
        cout << "next" << endl;
    }
    // ans = solution.threeSum(nums);
    // print ans
}
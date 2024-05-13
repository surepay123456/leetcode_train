
#include "../../include/header.h"

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {

        backtracking(nums);

        return ans;
        

    }

private:
    vector<vector<int>> ans;
    vector<int> list;
    unordered_set<int> hash_set;
    
    void backtracking(vector<int>& nums){

        //保存结果
        if(list.size() == nums.size()){
            ans.push_back(list);
            return;
        }

        //for 循环来表示宽度 // 如何引入标识符来表示不要重复的数字 用hash_table
        for(int i = 0; i <= nums.size() - 1; i++){
            if(hash_set.find(nums[i]) == hash_set.end()){ 
                list.push_back(nums[i]); //处理节点
                hash_set.insert(nums[i]);
                backtracking(nums);   //递归
                list.pop_back(); //回溯，撤销之前的节点 同时hash table删除
                hash_set.erase(nums[i]);
            }
        }

    }

};
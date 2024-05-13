
#include "../../include/header.h"

class Solution {
public:
    vector<string> binaryTreePaths(TreeNode* root) {
        //采用回溯
        if(root == nullptr) return {};

        path.push_back(root->val);
        backtracking(root);
        return result;
        

    }
    
    void backtracking(TreeNode* node){
        
        if(node == nullptr) return;
        
        
        if(!node->left && !node->right){
            //到叶子节点了 存结果
            string str;
            int n = path.size();
            for(int i = 0; i <= n - 1; i++){
                if(i == n - 1){
                   str += to_string(path[i]); 
                   continue;
                }
                str += to_string(path[i]);
                str += "->";
            }
            result.push_back(str);
            return;
        } 

        //分别回溯左右节点 
        if(node->left){
            path.push_back(node->left->val); 
            backtracking(node->left);
            path.pop_back();
        }

        if(node->right){
            path.push_back(node->right->val); 
            backtracking(node->right); 
            path.pop_back(); 
        }


    }

private:
    vector<string> result;
    vector<int> path;
};

TreeNode* vectorToTree(vector<int> vec){
    
}
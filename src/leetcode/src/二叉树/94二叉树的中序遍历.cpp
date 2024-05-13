
#include "../../include/header.h"

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
    //左 中 右 即为中序遍历
        if(root == nullptr) return {};
        vector<int> ans;
        
        vector<int> ans_left = inorderTraversal(root->left);
        
        ans.insert(ans.end(), ans_left.begin(), ans_left.end());
        
        ans.push_back(root->val);
        
        vector<int> ans_right = inorderTraversal(root->right);
        ans.insert(ans.end(), ans_right.begin(), ans_right.end());
        
        return ans;

    }
};
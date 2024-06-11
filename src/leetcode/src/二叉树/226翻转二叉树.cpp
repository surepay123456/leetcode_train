
#include "../../include/header.h"

class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
    
        // 交换左右叶子节点
        if(root == nullptr) return nullptr;
        swap(root->left, root->right);
        invertTree(root->left);
        invertTree(root->right);

        return root;
        
        
        
    }
};
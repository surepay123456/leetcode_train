
#include "../../include/header.h"

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        // 判断对称
        return judgeSymmetric(root->left, root->right);
        
    }

    bool judgeSymmetric(TreeNode* left, TreeNode* right){
        if(left == nullptr && right != nullptr) return false;
        if(right == nullptr && left != nullptr) return false;
        if(right == nullptr && left == nullptr) return true;
        if(left->val != right->val ) return false;
        return judgeSymmetric(left->left, right->right) && \
                judgeSymmetric(left->right, right->left);

    }
};
#include "../../include/header.h"

class Solution {
public:
    TreeNode* trimBST(TreeNode* root, int low, int high) {
        // 递归判断 左右子树是不是在[low, high] 中
        // if(root < low)  return 裁剪其右子树返回值
        // if(root > high) return 裁剪其左子树返回值
        // 在区间中的情况 那么就分别裁剪其左右子树 
        if(root == nullptr) return nullptr;
        if(root->val < low) return trimBST(root->right, low, high);
        else if(root->val > high) return trimBST(root->left, low, high);
        else{
            root->left = trimBST(root->left, low, high);
            root->right = trimBST(root->right, low, high);
        }

        return root;

    }
};
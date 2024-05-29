
#include "../../include/header.h"

class Solution {
public:
    bool isBalanced(TreeNode* root) {
        
        //后序递归遍历
        if(root == nullptr) return true;
        
        //计算左子树的最大深度与右子树的最大深度的差值
        int result = getHeight(root);
        if(result == -1) return false;
        else{
            return true;
        } 

    }
    
    int getHeight(TreeNode* root){
        //左右树的高度
        if(root == nullptr) return 0;
        int leftHeight = getHeight(root->left);
        if(leftHeight == -1 ) return -1;
        int rightHeight = getHeight(root->right);
        if(rightHeight == -1) return -1;

        if(abs(leftHeight - rightHeight) <= 1){
            return 1 + max(leftHeight, rightHeight);
        } 
        else{
            return -1;
        }
    }

};
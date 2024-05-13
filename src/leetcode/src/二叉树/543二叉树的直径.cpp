
#include "../../include/header.h"

class Solution {

private: 
    int ans;
    
    int depth(TreeNode* root){
        if(root == nullptr) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(L + R, ans);
        return max(L, R) + 1;
    }

public:
    int diameterOfBinaryTree(TreeNode* root) {
        //
        ans = 0;
        int n = depth(root);
        return ans;

    }
};
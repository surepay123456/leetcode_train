#include "../../include/header.h"

class Solution {
public:
    int countNodes(TreeNode* root) {
        // //计算节点个数的操作

        // //前序遍历
        // if(root == nullptr) return 0;
        // count = 0;
        // countTree(root);
        // return count;

       // 后序遍历的方法
       // 左边子树加上右边子树的数量
       // 由于是完全二叉树总是可以进行分解 

        //判断是完全二叉树 while(root->right) {if叶子节点返回true 计算层数 这个树返回2^n - 1 root = root->right}
        if(root == nullptr) return 0;
        
        //判断是否是完全二叉树 向左遍历的深度等于向右遍历的深度
        int rightDepth = 0; //深度
        TreeNode* node = root;
        while(node){
           rightDepth ++;
        //    if(!node->left && !node->right){
        //     return pow(2, n) - 1;
        //    } 
            node = node->right;
        }

        int leftDepth = 0;
        node = root;
        while (node)
        {
            leftDepth ++;
            node = node->left; 
        }

        if(rightDepth == leftDepth){
            return pow(2, rightDepth) - 1;
        }
        

        int left = countNodes(root->left);
        int right = countNodes(root->right);
        return left + right + 1;
    }
    // void countTree(TreeNode* root){
    //     if(root == nullptr) return ;
    //     else{
    //         count ++;
    //     }
    //     if(root->left) countTree(root->left);
    //     if(root->right) countTree(root->right);
    // }
    // int count;
};
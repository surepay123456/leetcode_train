#include "../../include/header.h"

class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        //找到目标节点
        if(root == nullptr) return root; //没有找到
        if(root->val == key){
            //叶子节点 右为空情况
            if(!root->right){
                TreeNode* tmp = root->left;
                delete root;
                return tmp;
            }
            //左为空右不为空的情况
            else if(root->right && !root->left){
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
            else{
                //将右子树最左边的节点的左孩子 设置为当前节点的左侧节点
                TreeNode* cur = root->right;
                while(cur->left){
                    cur = cur->left;
                }
                cur->left = root->left;
                TreeNode* tmp = root->right;
                delete root;
                return tmp;
            }
        }
        
        if(root->val > key)  root->left = deleteNode(root->left, key);
        if(root->val < key)  root->right = deleteNode(root->right, key);
        return root;

    }
};
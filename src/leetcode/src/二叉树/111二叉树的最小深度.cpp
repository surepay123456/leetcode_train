
#include "../../include/header.h"

class Solution {
public:
    int minDepth(TreeNode* root) {
        //深度: 根节点到此节点 通过的节点数
        //高度：此节点到叶子节点 通过的节点数

        // 先求左右子数的最小深度 返回再+1
        
        // if(root == nullptr) return 0;

        //注意是叶子节点 如果说有左子树但是没有右子树，该节点的最小深度不是1，因为
        //其不是叶子节点 
        // 递归法
        // int leftMinDepth = 0; 
        // int rightMinDepth = 0;
        // if(!root->left && !root->right) return 1; //判断是叶子节点 
        // if(root->left && !root->right) return minDepth(root->left) + 1;
        // if(root->right && !root->left) return minDepth(root->right) + 1;
        // return 1 + min(minDepth(root->left), minDepth(root->right));

        //  前序遍历 回溯法 自顶向下 求深度
        // if(root == nullptr) return 0;
        // result = INT_MAX;
        // calDepth(root, 1);
        // return result;

        // 层序遍历迭代写法
        queue<TreeNode*> que; //每次存储每层的 一共多少层就是最大深度，如果在每层之中检测是否有叶子节点
        //第一个检测到的就是 最小深度

        //空指针不入队列
        if(root == nullptr) return 0;
        que.push(root);
        int result = 0;
        while(!que.empty()){

            int n = que.size();
            TreeNode* node = nullptr;
            //标注这一层的深度
            result ++;
            for(int i = 1; i <= n; i++){
                node = que.front();
                //判断是否是叶子节点 
                if(!node->left && !node->right){
                    return result;
                }
                if(node->left) que.push(node->left);
                if(node->right) que.push(node->right);
                que.pop();
            } 
        }
        return result;
    }

// 前序遍历法
// private:
//     void calDepth(TreeNode* root, int depth){
//         if(root == nullptr) return ;
//         if(!root->left && !root->right){
//            result = min(result, depth); 
//         }
        
//         if(root->left){
//             calDepth(root->left, depth + 1);
//         } 

//         if(root->right){
//             calDepth(root->right, depth + 1);
//         }
//     }
//     int result;
};
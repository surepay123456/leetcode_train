#include <bits/stdc++.h>
#include <cmath>
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right)
        : val(x), left(left), right(right) {}
};

class Solution {
   public:
    int diameterOfBinaryTree(TreeNode *root) {
        //路劲可能不过根节点
        //经过当前节点的路径 左子树深度加上右子树深度
        result = 0;
        cout << depth(root);
        return result - 1;
    }

    int depth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        cout << "left" << endl;
        int leftDepth = depth(root->left);
        cout << leftDepth << endl;
        cout << "right" << endl;
        int rightDepth = depth(root->right);
        cout << rightDepth << endl;
        result = max(result, leftDepth + rightDepth + 1);
        return max(leftDepth, rightDepth) + 1;
    }

   private:
    int result;
};
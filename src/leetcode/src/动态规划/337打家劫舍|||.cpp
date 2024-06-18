#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
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
    int rob(TreeNode *root) {
        //二叉树打家劫舍
        // 偷了父节点 子节点就不能再偷
        if (root == nullptr) {
            return 0;
        }

        vector<int> result = robTree(root);
        return max(result[0], result[1]);
    }

   private:
    vector<int> robTree(TreeNode *root) {
        if (root == nullptr) return {0, 0};
        vector<int> maxLeft = robTree(root->left);
        vector<int> maxRight = robTree(root->right);
        // 偷当前root
        // { 偷 ， 不偷} 所得的最大值
        int steal = maxLeft[1] + maxRight[1] + root->val;
        // 不偷当前root 节点可偷可不偷
        int notsteal =
            max(maxLeft[0], maxLeft[1]) + max(maxRight[0], maxRight[1]);
        return {steal, notsteal};
    }
};
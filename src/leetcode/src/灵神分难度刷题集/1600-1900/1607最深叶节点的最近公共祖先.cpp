#include <bits/stdc++.h>

#include <functional>
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
    TreeNode *lcaDeepestLeaves(TreeNode *root) {
        TreeNode *ans = nullptr;
        // 返回当前节点的深度
        int maxDepth = -1;
        function<int(TreeNode *, int)> dfs = [&](TreeNode *node, int depth) {
            if (node == nullptr) {
                maxDepth = max(maxDepth, depth);
                return depth;
            }
            int leftDepthMax = dfs(node->left, depth + 1);
            int rightDepthMax = dfs(node->right, depth + 1);
            if (leftDepthMax == rightDepthMax && leftDepthMax == maxDepth) {
                ans = node;
            }
            return max(leftDepthMax, rightDepthMax);
        };
        dfs(root, 0);
        return ans;
    }
};
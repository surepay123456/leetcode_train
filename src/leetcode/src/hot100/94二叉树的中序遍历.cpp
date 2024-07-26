#include <bits/stdc++.h>

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
    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) {
            return {};
        }
        traverse(root);
        return ans;
    }

   private:
    vector<int> ans;
    void traverse(TreeNode *node) {
        if (node->left) {
            traverse(node->left);
        }
        ans.push_back(node->val);
        if (node->right) {
            traverse(node->right);
        }
    }
};
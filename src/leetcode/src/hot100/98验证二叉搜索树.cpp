#include <bits/stdc++.h>

#include <climits>
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
    bool isValidBST(TreeNode *root) {
        if (!root) {
            return true;
        }
        long long lower = LONG_MIN;
        long long upper = LONG_MAX;
        return isInRange(root->left, lower, root->val) &&
               isInRange(root->right, root->val, upper);
    }

   private:
    bool isInRange(TreeNode *node, int lowerBound, int upperBound) {
        if (!node) {
            return true;
        }
        return node->val > lowerBound && node->val < upperBound &&
               isInRange(node->left, lowerBound, node->val) &&
               isInRange(node->right, node->val, upperBound);
    }
};
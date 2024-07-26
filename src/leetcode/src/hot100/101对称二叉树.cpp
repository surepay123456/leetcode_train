#include <bits/stdc++.h>

#include <cmath>
#include <deque>
#include <iomanip>
#include <ios>
#include <queue>
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
    bool isSymmetric(TreeNode *root) {
        // left == right
        if (!root) {
            return true;
        }
        return isEqual(root->left, root->right);
    }
    bool isEqual(TreeNode *left, TreeNode *right) {
        if (!left && !right) {
            return true;
        }
        if (!left && right) {
            return false;
        }
        if (left && !right) {
            return false;
        }
        return left->val == right->val && isEqual(left->left, right->right) &&
               isEqual(left->right, right->left);
    }
};

int main() {
    // 数组建立二叉树
}
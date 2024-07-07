#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
};
class Solution {
   public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        // 空指针的情况
        if (!p && q) {
            return false;
        }
        if (p && !q) {
            return false;
        }
        if (!p && !q) {
            return true;
        }

        if (p->val != q->val) {
            return false;
        }

        // 比较左子树和右子树
        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};
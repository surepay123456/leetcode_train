#include <bits/stdc++.h>

#include <cmath>
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
    void flatten(TreeNode *root) {
        //前序遍历
        //原地操作
        // root 节点 左右节点展开为链表后  需要知道链表的首尾节点
        // auto temp = root->right;
        // root->right = root->left;
        // 左链表的最后一个节点->right = temp
        // 循环中要设置第一个节点后末尾节点
        if (!root) {
            return;
        }
        flattenList(root);
    }

   private:
    TreeNode *flattenList(TreeNode *node) {
        TreeNode *left = node->left;
        TreeNode *right = node->right;
        TreeNode *last = node;
        node->left = nullptr;
        if (left) {
            node->right = left;
            last = flattenList(left);
        }
        last->right = right;
        if (right) {
            last = flattenList(right);
        }
        return last;
    }
};
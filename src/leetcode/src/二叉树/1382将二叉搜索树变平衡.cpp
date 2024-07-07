#include <bits/stdc++.h>

#include <vector>
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
    TreeNode* balanceBST(TreeNode* root) {
        traverse(root);
        return getBST(vec, 0, vec.size() - 1);
    }

   private:
    vector<int> vec;
    void traverse(TreeNode* root) {
        if (!root) {
            return;
        }
        // 先得到左边的节点值
        traverse(root->left);
        vec.push_back(root->val);
        traverse(root->right);
    }
    TreeNode* getBST(vector<int>& vec, int start, int end) {
        if (start > end) {
            return nullptr;
        }
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(vec[mid]);
        root->left = getBST(vec, start, mid - 1);
        root->right = getBST(vec, mid + 1, end);
        return root;
    }
};
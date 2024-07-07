#include <bits/stdc++.h>
#include <math.h>

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
    int sumNumbers(TreeNode* root) {
        // 路径走到叶子节点 再返回， 回溯的一个过程
        result = 0;
        if (root == nullptr) {
            return 0;
        }
        path.push_back(root->val);
        backtracing(root);
        return result;
    }

   private:
    vector<int> path;
    int result;
    void backtracing(TreeNode* root) {
        if (root->left == nullptr && root->right == nullptr) {
            result += pathToNum(path);
            return;
        }
        // 不是叶子节点
        if (root->left) {
            path.push_back(root->left->val);
            backtracing(root->left);
            path.pop_back();
        }

        if (root->right) {
            path.push_back(root->right->val);
            backtracing(root->right);
            path.pop_back();
        }
    }
    int pathToNum(vector<int>& path) {
        int sum = 0;
        for (int i = 0; i < path.size(); i++) {
            sum += path[i] * pow(10, path.size() - 1 - i);
        }
        return sum;
    }
};
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
    int kthSmallest(TreeNode *root, int k) {
        //从二叉搜索树来构建数组
        // 自底向上构建排序数组
        // woc 第k小的数组 那么构建过程中如果数组大小等于k了 即可停止
        vector<int> nums;
        buildVector(root, nums, k);
        return nums[k - 1];
    }

   private:
    void buildVector(TreeNode *node, vector<int> &nums, int &k) {
        if (!node) {
            return;
        }
        buildVector(node->left, nums, k);
        if (nums.size() == k) {
            return;
        }
        nums.push_back(node->val);
        if (nums.size() == k) {
            return;
        }
        buildVector(node->right, nums, k);
    }
};
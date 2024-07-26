#include <bits/stdc++.h>

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
    vector<vector<int>> levelOrder(TreeNode *root) {
        if (!root) {
            return {};
        }

        queue<TreeNode *> que;
        que.push(root);
        vector<vector<int>> ans;
        while (!que.empty()) {
            int n = que.size();
            ans.resize(ans.size() + 1);
            while (n--) {
                TreeNode *temp = que.front();
                que.pop();
                ans[ans.size() - 1].push_back(temp->val);
                if (temp->left) {
                    que.push(temp->left);
                }
                if (temp->right) {
                    que.push(temp->right);
                }
            }
        }
        return ans;
    }
};
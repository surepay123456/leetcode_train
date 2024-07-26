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
    vector<int> rightSideView(TreeNode *root) {
        //层序遍历 保存最后一个节点
        if (!root) {
            return {};
        }
        queue<TreeNode *> que;
        vector<int> ans;
        que.push(root);
        while (!que.empty()) {
            int n = que.size();
            while (n) {
                TreeNode *temp = que.front();
                que.pop();
                if (temp->left) {
                    que.push(temp->left);
                }
                if (temp->right) {
                    que.push(temp->right);
                }
                if (n == 1) {
                    ans.push_back(temp->val);
                }
                n --;
            }
        }
        return ans;
    }
};
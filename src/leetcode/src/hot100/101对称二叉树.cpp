#include <bits/stdc++.h>

#include <cmath>
#include <deque>
#include <iomanip>
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
        //层序遍历
        if (!root) {
            return true;
        }
        deque<TreeNode *> que;
        que.push_front(root);
        while (!que.empty()) {
            int num = que.size();
            while (num--) {
                TreeNode *temp = que.front();
                que.pop_front();

                if (!temp) {
                    que.push_back(nullptr);
                    que.push_back(nullptr);
                } else {
                    que.push_back(temp->left);
                    que.push_back(temp->right);
                }
            }
            //检测现有的que是否是对称的
            vector<TreeNode *> vec(que.begin(), que.end());
            int s = 0;
            int e = vec.size() - 1;
            while (s < e) {
                if (!vec[s] && !vec[e]) {
                    s++;
                    e--;
                    continue;
                }
                if (!vec[s] && vec[e]) {
                    return false;
                }
                if (vec[s] && !vec[e]) {
                    return false;
                }
                if (vec[s]->val != vec[e]->val) {
                    return false;
                }
                s++;
                e--;
            }
        }
        return true;
    }
};

TreeNode *vecToTree(vector<int> &vec) {
    // index = i 的节点 其叶子节点是哪些呢
}

int main() {
    // 数组建立二叉树
}
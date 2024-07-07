#include <bits/stdc++.h>

#include <queue>
using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
   public:
    Node* connect(Node* root) {
        // 层序遍历
        queue<Node*> que;
        if (!root) {
            return nullptr;
        }
        que.push(root);
        while (!que.empty()) {
            // 当前层
            int n = que.size();
            Node* cur = nullptr;
            Node* pre = nullptr;
            for (int i = 0; i < n; i++) {
                cur = que.front();
                if (cur->left) {
                    que.push(cur->left);
                }
                if (cur->right) {
                    que.push(cur->right);
                }
                que.pop();
                if (pre) {
                    pre->next = cur;
                }
                pre = cur;
            }
        }
        return root;
    }
};
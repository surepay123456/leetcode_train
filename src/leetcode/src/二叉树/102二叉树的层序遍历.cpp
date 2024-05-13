
#include "../../include/header.h"

class Solution {


public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (!root) return {};
        queue<TreeNode*> que;
        que.push(root);

        vector<vector<int>> ans;
        vector<int> level_vec;
        while(!que.empty()){
            //循环当前层的节点数
            int n = que.size();
            //当前层
            while(n){
                level_vec.push_back(que.front()->val);
                if(que.front()->left) que.push(que.front()->left);
                if(que.front()->right) que.push(que.front()->right);
                que.pop();
                n--;
            }
            ans.push_back(level_vec);
            level_vec.clear();
        }
        return ans;
    }
};
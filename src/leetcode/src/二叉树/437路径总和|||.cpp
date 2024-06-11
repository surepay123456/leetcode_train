#include <bits/stdc++.h>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int num) : val(num), left(nullptr), right(nullptr) {}
    TreeNode(int num, TreeNode* left, TreeNode* right)
        : val(num), left(left), right(right) {}
};
class Solution {
   public:
    int pathSum(TreeNode* root, int targetSum) {

    }
    private: 
    vector<int> path;
    vector<vector<int>> results;
    
    // 每一个节点都作为初始节点来进行枚举 
    void searchTreeNode(TreeNode* root, int targetSum){
        
    }
    
    // 首节点加入sum 
    // if(targetSum == 0) results.push_back(path)
    // path.push_back(root->val)
    // searchTreeNode(root->left , targetSum - root->val)
    // path.pop_back();
    // path.push_back(                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                          il/.)
    // searchTreeNode(root->right , targetSum - root->val)
    // 
    // 
};
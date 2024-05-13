
#include "../../include/header.h"

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sum = 0;
        unordered_set<vector<int>> hashSet;
        backtracking(candidates, sum, target);
        return ans;
    }
private:
    vector<vector<int>> ans;
    vector<int> path;
    int sum;

    void backtracking(vector<int>& candidates, int sum, int target){
        if(sum == target){
            //判断该组合是否已经在ans中
            sort(path.begin(), path.end());
            if(hashSet.find(path) == hashSet.end()){
                ans.push_back(path);
                hashSet.insert(path); 
                return;
            }
        }
        
        if(sum > target){
            return;
        }

        for(int i = 0; i <= candidates.size() - 1; i++){
            path.push_back(candidates[i]);
            sum += candidates[i];
            backtracking(candidates, sum, target);
            path.pop_back();
            sum -= candidates[i]; 
        }
    }


};

int main(){
    vector<int> candidates{2, 3, 5};
    Solution solution;

}
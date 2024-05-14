#include "bits/stdc++.h"

#include "dbg.h"
#include <cstddef>
class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.clear();
        results.clear();
        int target = static_cast<int>(graph.size() - 1);
        // size_t 
        backtracking(0, target, graph);
        return results;
        // size_t a;

    }
private:
    vector<int> path;
    vector<vector<int>> results;
    void backtracking(int num, const int& target, const vector<vector<int>>& graph){
        if(num == target){
            path.push_back(num);
            dbg(path);
            results.push_back(path);
            path.pop_back();
            return;
        }
        //临接矩阵遍历
        // int sizeVec = static_cast<int>(graph[num].size() - 1);
        for(int i = 0; i <= static_cast<int>(graph[num].size()) - 1; i++){
            dbg(graph[num]);
            // cout << graph[num].size() << endl;
            dbg(graph[num].size());
            dbg(i);
            path.push_back(num);
            // cout << "push num :" << num << endl;
            backtracking(graph[num][i], target, graph);
            // cout << "pop num :" << num << endl;
            path.pop_back();
        }
    }
};

int main(){
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{},{4},{}};
    Solution solu;
    vector<vector<int>> results;
    results =  solu.allPathsSourceTarget(graph);
    return 0;
    
}
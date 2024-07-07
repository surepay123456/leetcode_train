#include <bits/stdc++.h>
#include <vector>
#include <dbg.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        path.push_back(0);
        dfs(graph, 0);
        return result;
        
    }
private:
    vector<vector<int>> result;
    vector<int> path;

    void dfs(vector<vector<int>> & graph, int index){
        if (index == graph.size() - 1) {
            result.push_back(path); 
            return;
        } 
        for (int i = 0; i < graph[index].size(); i++) {
            path.push_back(graph[index][i]);
            dfs(graph, graph[index][i]);
            path.pop_back();
        }
    }
};

int main(){
    vector<vector<int>> graph = {{4,3,1},{3,2,4},{3},{4},{}};
    Solution solution;
    vector<vector<int>> result = solution.allPathsSourceTarget(graph);
    dbg(result);
    return 0;
}
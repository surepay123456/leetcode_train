#include <bits/stdc++.h>
#include <dbg.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        // 找是否存在路径的问题
        // 由 source 搜索到 destination 如果搜索到则立即返回
        // 找连通块 //遍历edges 如果有 source 或者 destination 则开始搜索
        //
        // vector<vector<int>> map(n, vector<int>(n, 0));
        vector<vector<int>> adj;
        adj.resize(n);
        for (int i = 0; i < edges.size(); i ++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }    
        // dbg(adj);
        vector<bool> visited(n, false);
        if (source == destination) {
            return true;
        }
        if (adj[source].size() == 0 || adj[destination].size() == 0) {
            return false;
        }
        return dfsSearch(adj, visited, source, destination);
        
    }

   private:
    bool dfsSearch(vector<vector<int>>& adj, vector<bool>& visited, int index,
                   int destination) {
        if (index == destination) {
            return true;
        }
        visited[index] = true;
        bool finded = false;
        for (int i = 0; i < adj[index].size(); i ++) {
            if (visited[adj[index][i]]) {
                continue;
            }
            if (dfsSearch(adj, visited, adj[index][i], destination)) {
                return true;
            }
        }
        return false;
    }
};

int main() {
    vector<vector<int>> edges = {{0, 7}, {0, 8}, {6, 1}, {2, 0}, {0, 4},
                                 {5, 8}, {4, 7}, {1, 3}, {3, 5}, {6, 5}};
    Solution solution;
    if (solution.validPath(10, edges, 7, 5)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }
    return 0;
}
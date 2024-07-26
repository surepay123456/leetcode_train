#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
#include <dbg.h>
class Solution {
   public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n - 1) {
            return -1;
        }
        // 查找不连通的子图个数 操作数为个数减一
        int num = 0;
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < connections.size(); i++) {
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        // dbg(adj);
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                num ++;
                dfs(adj, visited, i);
            }
        }
        return num - 1;
        
    }

   private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
        visited[start] = true;
        for (int i = 0; i < adj[start].size(); i++) {
            if (visited[adj[start][i]]) {
                continue;
            }
            dfs(adj, visited, adj[start][i]);
        }
    }
};

int main(){
    vector<vector<int>> connections = {{0,1},{0,2},{0,3},{1,2},{1,3}};
    Solution solution;
    cout << solution.makeConnected(6, connections);
    return 0;
}
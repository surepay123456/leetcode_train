#include <bits/stdc++.h>

#include <algorithm>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<vector<int>> results(n, vector<int>());
        vector<bool> visited(n, false);
        for (int i = 0; i < n; i++) {
            fill(visited.begin(), visited.end(), false);
            dfs(adj, visited, i);
            for (int j = 0; j < n; j++) {
                if (i == j) {
                    continue;
                }
                if (visited[j]) {
                    results[i].push_back(j);
                }
            }
        }
        return results;
    }
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
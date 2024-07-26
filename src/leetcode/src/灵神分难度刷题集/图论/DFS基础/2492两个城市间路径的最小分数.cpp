#include <bits/stdc++.h>

#include <climits>
#include <vector>
using namespace std;

class Solution {
   public:
    int minScore(int n, vector<vector<int>>& roads) {
        // 1的连通图中边最小的
        vector<vector<vector<int>>> adj(n, vector<vector<int>>());
        for (int i = 0; i < roads.size(); i++) {
            adj[roads[i][0] - 1].push_back({roads[i][1] - 1, roads[i][2]});
            adj[roads[i][1] - 1].push_back({roads[i][0] - 1, roads[i][2]});
        }
        vector<bool> visited(n, false);
        int result = INT_MAX; 
        dfs(adj, visited, 0, result);
        return result;
    }

   private:
    void dfs(vector<vector<vector<int>>>& adj, vector<bool>& visited, int start,
            int& minL) {
        visited[start] = true;
        for (int i = 0; i < adj[start].size(); i++) {
            minL = min(adj[start][i][1], minL);
            if (visited[adj[start][i][0]]) {
                continue;
            }
            dfs(adj, visited, adj[start][i][0], minL);
        }
    }
};

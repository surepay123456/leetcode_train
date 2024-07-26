#include <bits/stdc++.h>

#include <iostream>
#include <vector>
#include <dbg.h>
using namespace std;

class Solution {
   public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        // 4 2 1
        // 4  2 1  4 * 3 + 2 * 1
        // 这个题本来用并查集做很清晰，现在用dfs做
        // 目标是检查出每个连通子图里面的数目

        vector<bool> visited(n, false);
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        // dbg(adj);
        vector<int> sums;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                sums.push_back(dfs(adj, visited, i));
            }
        }
        // dbg(sums);
        // 后缀和
        sums.push_back(0);
        vector<int> leftSum(sums.size(), 0);
        for (int i = sums.size() - 2; i >= 0; i--) {
            leftSum[i] = leftSum[i + 1] + sums[i + 1];
        }
        // dbg(leftSum);
        long long result = 0;
        for (int i = 0; i < sums.size(); i++) {
            result += (long long)leftSum[i] * sums[i];
        }
        return result;
    }

   private:
    int dfs(vector<vector<int>>& adj, vector<bool>& visited, int start) {
        visited[start] = true;
        int sum = 1;
        for (int i = 0; i < adj[start].size(); i++) {
            if (visited[adj[start][i]]) {
                continue;
            }
            sum += dfs(adj, visited, adj[start][i]);
        }
        return sum;
    }
};

int main(){
    vector<vector<int>> edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    Solution solution;
    cout << solution.countPairs(7, edges);
    return 0;
}
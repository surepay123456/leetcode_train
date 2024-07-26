#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
#include <dbg.h>
class Solution {
   public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        // 完全连通
        // 怎么判断一个连通图是完全连通的呢
        //  dfs后 获得连通图中节点数量 判断adj的长度== 数量 -1
        vector<vector<int>> adj(n, vector<int>());
        for (int i = 0; i < edges.size(); i++) {
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<bool> visited(n, false);
        int result = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                vector<int> haveList;
                dfs(adj, visited, i, haveList);
                // dbg(haveList); 
                // check
                for (int j = 0; j < haveList.size(); j++) {
                    if (adj[haveList[j]].size() != haveList.size() - 1) {
                        break;
                    }
                    if (j == haveList.size() - 1) {
                        result++;
                    }
                }
            }
        }
        return result;
    }

   private:
    void dfs(vector<vector<int>>& adj, vector<bool>& visited, int start,
             vector<int>& haveList) {
        visited[start] = true;
        haveList.push_back(start);
        for (int i = 0; i < adj[start].size(); i++) {
            if (visited[adj[start][i]]) {
                continue;
            }
            dfs(adj, visited, adj[start][i], haveList);
        }
    }
};

int main() {
    int n = 6;
    vector<vector<int>> edges = {{0, 1}, {0, 2}, {1, 2}, {3, 4}, {3, 5}};
    Solution solution;
    cout << solution.countCompleteComponents(n, edges);
    return 0;
}
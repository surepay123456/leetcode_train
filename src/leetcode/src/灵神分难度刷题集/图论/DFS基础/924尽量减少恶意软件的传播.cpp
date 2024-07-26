#include <algorithm>
#include <bits/stdc++.h>
#include <dbg.h>

#include <climits>
#include <iostream>
#include <ratio>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
   public:
    int minMalwareSpread(vector<vector<int>>& graph, vector<int>& initial) {
        // graph 是连接关系， initial是最初的感染节点
        //  寻找只包含一个节点的最大连通块
        vector<vector<int>> adj(graph.size(), vector<int>());
        unordered_set<int> set(initial.begin(), initial.end());
        for (int i = 0; i < graph.size(); i++) {
            for (int j = 0; j < graph.size(); j++) {
                if (i == j) {
                    continue;
                }
                if (graph[i][j] == 1) {
                    adj[i].push_back(j);
                }
            }
        }
        dbg(adj);
        int max_num = INT_MIN;
        sort(initial.begin(), initial.end());
        int result = initial[0];
        dbg(initial);
        vector<bool> visited(graph.size(), false);
        for (int i = 0; i < initial.size(); i++) {
            if (!visited[initial[i]]) {
                int state = -1;
                int num = 0;
                num = dfs(adj, visited, set, initial[i], state);
                dbg(visited);
                dbg(initial[i]);
                dbg(num);
                dbg(state);
                if (state == -1 && max_num < num) {
                    result = initial[i];
                    max_num = num;
                    dbg(max_num);
                }
            }
        }
        return result;
    }

   private:
    int dfs(vector<vector<int>>& adj, vector<bool>& visited,
            unordered_set<int>& set, int start, int& state) {
        visited[start] = true;
        int num = 1;
        for (int i = 0; i < adj[start].size(); i++) {
            if (visited[adj[start][i]]) {
                continue;
            }
            // 连通块 查询当前是否是感染节点
            //
            if (set.count(adj[start][i])) {
                state = -2;
            }
            num += dfs(adj, visited, set, adj[start][i], state);
        }
        return num;
    }
};

int main() {
    vector<vector<int>> graph = {
        { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1 },
        { 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 0, 1, 0, 0, 0 },
        { 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0 },
        { 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0 },
        { 0, 0, 0, 1, 0, 1, 0, 0, 1, 1, 0 },
        { 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0 },
        { 0, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0 },
        { 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0 }, { 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1 }
    };
    Solution solution;
    vector<int> initial = {7, 8, 6, 2, 3};
    cout << solution.minMalwareSpread(graph, initial) << endl;
    return 0;
}

#include <bits/stdc++.h>
#include <dbg.h>

#include <cstddef>
#include <functional>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), 0);
        // 0 1 2 分别表示未访问 以及访问但在栈中 终点节点
        function<bool(int)> dfs = [&](int x) {
            if (visited[x] != 0) {
                return visited[x] == 2;
            }
            visited[x] = 1;
            for (int i = 0; i < graph[x].size(); i++) {
                if (!dfs(graph[x][i])) {
                    return false;
                }
            }
            visited[x] = 2;
            return true;
        };
        vector<int> results;
        for (int i = 0; i < graph.size(); i++) {
            if (dfs(i)) {
                results.push_back(i);
            }
        }
        return results;
    }
};
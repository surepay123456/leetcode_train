#include <bits/stdc++.h>
#include <dbg.h>

#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        // 用几何关系建立连通图 找最大连通图即可
        //  注意是有向边
        vector<vector<int>> adj(bombs.size(), vector<int>());
        for (int i = 0; i < bombs.size(); i++) {
            for (int j = 0; j < bombs.size(); j++) {
                if (i == j) {
                    continue;
                }
                long long dx = bombs[i][0] - bombs[j][0];
                long long dy = bombs[i][1] - bombs[j][1];
                if (dx * dx + dy * dy <= (long long ) bombs[i][2] * bombs[i][2]) {
                    adj[i].push_back(j);
                }
            }
        }
        int results, size;
        int max_size = INT_MIN;
        vector<bool> visited(bombs.size(), false);
        function<void(int)> dfs = [&](int x) {
            visited[x] = true;
            size++;
            for (int i = 0; i < adj[x].size(); i++) {
                if (visited[adj[x][i]]) {
                    continue;
                }
                dfs(adj[x][i]);
            }
        };
        for (int i = 0; i < adj.size(); i++) {
            fill(visited.begin(), visited.end(), false);
            size = 0;
            dfs(i);
            if (size > max_size) {
                results = i;
                max_size = size;
            }
        }
        return max_size;
    }
};

int main() {
    vector<vector<int>> bombs = {{2, 1, 3}, {6, 1, 4}};
    Solution solution;
    cout << solution.maximumDetonation(bombs) << endl;
    return 0;
}
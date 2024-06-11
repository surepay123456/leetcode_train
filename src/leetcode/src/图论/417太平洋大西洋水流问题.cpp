#include <memory>
#include <vector>

#include "header.h"
class Solution {
   public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        // 对当前节点进行搜索 如果能够触摸到两大样的边界 就可以加入results
        // 搜索策略是 如果当前节点大于等于相邻的节点 就可以在相邻的节点再搜索
        // 触碰到边界迅速返回 搜索过程中标记节点 随后只用搜索未标记即可
        int m = heights.size();
        int n = heights[0].size();
        vector<vector<bool>> visitedPacific =
            vector<vector<bool>>(m, vector<bool>(n, false));

        vector<vector<bool>> visitedAtlantic =
            vector<vector<bool>>(m, vector<bool>(n, false));

        // 从边界区域开始遍历 从 低 到 高来扩展
        for (int i = 0; i < m; i++) {
            dfs(heights, visitedPacific, i, 0);
            dfs(heights, visitedAtlantic, i, n - 1);
        }

        for (int i = 0; i < n; i++) {
            dfs(heights, visitedPacific, 0, i);
            dfs(heights, visitedAtlantic, m - 1, i);
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedPacific[i][j] && visitedAtlantic[i][j]) {
                    results.push_back({i, j});
                }
            }
        }
        return results;
    }

   private:
    vector<vector<int>> results;
    int diretion[4][2] = {0, 1, 0, -1, -1, 0, 1, 0};
    void dfs(vector<vector<int>>& heights, vector<vector<bool>>& visited, int x,
             int y) {
        visited[x][y] = true;
        for (int i = 0; i < 4; i++) {
            int nextX = x + diretion[i][0];
            int nextY = y + diretion[i][1];


            // 判断边界条件
            if (nextX < 0 || nextX >= heights.size() || nextY < 0 ||
                nextY >= heights[0].size())
                continue;

            if (visited[nextX][nextY]) continue;
            // 如果下一个节点 比现在这个节点要低 那么不扩展
            if (heights[nextX][nextY] < heights[x][y]) continue;

            dfs(heights, visited, nextX, nextY);
        }
    }
};
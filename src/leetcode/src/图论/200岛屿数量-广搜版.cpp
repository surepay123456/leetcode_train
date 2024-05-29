#include <queue>
#include <ratio>
#include <type_traits>
#include <utility>
#include <vector>

#include "header.h"

class Solution {
   public:
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<bool>> visited = vector<vector<bool>>(
            grid.size(), vector<bool>(grid[0].size(), false));
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!visited[i][j] && grid[i][j] == '1') {
                    result++;
                    bfs(grid, visited, i, j);
                }
            }
        }
        return result;
    }

   private:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    // 一次bfs将其所连的岛屿全部标记
    void bfs(vector<vector<char>>& grid, vector<vector<bool>>& visited, int x,
             int y) {
        int nextX = 0;
        int nextY = 0;

        queue<pair<int, int>> que;

        que.push({x, y});
        visited[x][y] = true;
        int curX;
        int curY;
        while (!que.empty()) {
            pair<int, int> cur = que.front();
            que.pop();
            curX = cur.first;
            curY = cur.second;

            for (int i = 0; i < 4; i++) {
                nextX = curX + direction[i][0];
                nextY = curY + direction[i][1];
                // 判断边界条件
                if (nextX < 0 || nextX >= grid.size() || nextY < 0 ||
                    nextY >= grid[0].size()) {
                    continue;
                }

                if (!visited[nextX][nextY] && grid[nextX][nextY] == '1') {
                    que.push({nextX, nextY});
                    visited[nextX][nextY] = true;
                }

                // bfs 利用队列来操作 进入队列就标记
                // 如果出来才标记会怎么样？ 同一节点会多次入队
                // 当前是岛屿 并且没有被标记
            }
        }
    }
};
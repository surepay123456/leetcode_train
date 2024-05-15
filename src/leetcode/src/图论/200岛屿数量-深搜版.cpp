#include <header.h>

#include <cstdint>
#include <vector>

class Solution {
   public:
    int numIslands(vector<vector<char>> &grid) {
        // DFS 写法
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited =
            vector<vector<bool>>(m, vector<bool>(n, false));

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 如果没有被访问  标记过 并且是陆地 就dfs
                // 将其相连的所有陆地全部标记
                if (!visited[i][j] && grid[i][j] == '1') {
                    visited[i][j] = true;
                    result++;
                    dfs(grid, visited, i, j);

                    
                }
            }
        }
        return result;
    }

   private:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    void dfs(vector<vector<char>> &grid, vector<vector<bool>> &visited, int x,
             int y) {
        // 四个方向来遍历 如果有陆地 再进行dfs 此为深度遍历
        int curX = x;
        int curY = y;
        for (int i = 0; i < 4; i++) {
            curX = x + direction[i][0];
            curY = y + direction[i][1];
            // 判断是否超出了界限
            if (curX < 0 || curX >= grid.size() || curY < 0 ||
                curY >= grid[0].size()) {
                continue;
            }
            // 判断这个是否是岛屿 并且这个岛屿是否已经被标记
            if (!visited[curX][curY] && grid[curX][curY] == '1') {
                visited[curX][curY] = true;
                dfs(grid, visited, curX, curY);
            }
        }
    }
};
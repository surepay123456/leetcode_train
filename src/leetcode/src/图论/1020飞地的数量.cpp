#include "header.h"

class Solution {
   public:
    int numEnclaves(vector<vector<int>> &grid) {
        // DFS 写法
        int m = grid.size(), n = grid[0].size();

        vector<vector<bool>> visited =
            vector<vector<bool>>(m, vector<bool>(n, false));

        int result = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // 如果没有被访问  标记过 并且是陆地 就dfs
                // 将其相连的所有陆地全部标记
                if (!visited[i][j] && grid[i][j] == 1) {
                    if (i == 0 || i == m - 1 || j == 0 || j == n - 1)
                        continue;  // 边界的无法扩散的中间 即使开始是连接的
                    // 比如说现在先到边界点 其没有弄到中间去，
                    // 导致之后dfs中间的1的时候，
                    // 看不到岛屿连接的边界，因为此时以及visited了
                    //  result++;
                    visited[i][j] = true;
                    bool reachBound = false;
                    int num = dfs(grid, visited, i, j, reachBound);
                    if (reachBound)
                        continue;
                    else
                        result += num;
                }
            }
        }
        return result;
    }

   private:
    int direction[4][2] = {0, 1, 0, -1, 1, 0, -1, 0};
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x,
            int y, bool &reachBound) {
        // 四个方向来遍历 如果有陆地 再进行dfs 此为深度遍历
        int count = 1;
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
            if (!visited[curX][curY] && grid[curX][curY] == 1) {
                // 这里判断是否是边界
                if (curX == 0 || curX == grid.size() - 1 ||
                    curY == grid[0].size() - 1 || curY == 0)
                // return 0;
                {
                    reachBound = true;
                }
                // 此处不能一下子就返回了
                // 因为还没有找到所有节点的岛屿的，
                // 这样提前返回dfs，会导致还未访问但是
                // 连接了的节点被视作飞地

                // 解决办法 ： 立一个flag 表示这个岛屿接触到了边界 用
                //  不是边界 则继续深度优先
                visited[curX][curY] = true;
                bool flag = false;

                int nextCount = dfs(grid, visited, curX, curY, flag);
                count += nextCount;
                reachBound |= flag;
            }
        }
        return count;
    }
};
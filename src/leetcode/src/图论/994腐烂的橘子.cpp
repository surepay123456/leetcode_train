#include <utility>
#include <vector>

#include "header.h"

class Solution {
   public:
    int orangesRotting(vector<vector<int>>& grid) {
        // 先找到每个腐烂的橘子 位置
        // 每一回合 进行BFS 如果说 感染的橘子变为0了 即 que
        // 空了则返回了最小分钟数 再遍历一遍 网格 如果有新鲜橘子 则返回-1
        queue<pair<int, int>> que;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    que.push({i, j});
                }
            }
        }

        int minutes = 0;
        while (!que.empty()) {
            // 这是一分钟感染扩散
            // 什么时候表示已经扩散完？

            int num = que.size();
            while (num) {
                pair<int, int> curIndex = que.front();
                que.pop();
                int curX = curIndex.first;
                int curY = curIndex.second;
                for (int i = 0; i < 4; i++) {
                    int nextX = curX + directions[i][0];
                    int nextY = curY + directions[i][1];
                    //判断边界条件
                    if (nextX < 0 || nextX >= grid.size() || nextY < 0 ||
                        nextY >= grid[0].size()) {
                        continue;
                    }
                    // 如果是 新鲜橘子 则感染 并且加入到que中
                    if (grid[nextX][nextY] == 1) {
                        grid[nextX][nextY] = 2;
                        que.push({nextX, nextY});
                    }
                }
                num--;
            }
            minutes++;
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        return minutes == 0 ? 0 : minutes - 1;
    }

   private:
    int directions[4][2] = {1, 0, -1, 0, 0, 1, 0, -1};
};
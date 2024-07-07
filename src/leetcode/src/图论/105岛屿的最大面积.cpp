#include <bits/stdc++.h>

#include <algorithm>
#include <scoped_allocator>
#include <vector>
using namespace std;

class Solution {
   public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int max_num = 0;
        vector<vector<bool>> visited(grid.size(),
                                     vector<bool>(grid[0].size(), false));
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 1 && visited[i][j] == false) {
                    max_num = max(max_num, bfs(grid, i, j, visited));
                }
            }
        }
        return  max_num;
    }

    vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    int bfs(vector<vector<int>>& map, int curX, int curY,
            vector<vector<bool>>& visited) {
        queue<pair<int, int>> que;
        que.push(make_pair(curX, curY));
        visited[curX][curY] = true;
        int num = 1;
        while (!que.empty()) {
            pair<int, int> tempIndex;
            tempIndex = que.front();
            que.pop();
            for (int i = 0; i < 4; i++) {
                int nextX = tempIndex.first + direction[i][0];
                int nextY = tempIndex.second + direction[i][1];
                if (nextX >= map.size() || nextX < 0 ||
                    nextY >= map[0].size() || nextY < 0) {
                    continue;
                }
                if (map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                    visited[nextX][nextY] = true;
                    num++;
                    que.push(make_pair(nextX, nextY));
                }
            }
        }
        return num;
    }
};
#include <bits/stdc++.h>

#include <cstdint>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int bfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, int curX,
        int curY) {
    bool islated = true;
    queue<pair<int, int>> que;
    que.push(make_pair(curX, curY));
    visited[curX][curY] = true;
    if (curX == 0 || curX == grid.size() - 1 || curY == 0 ||
        curY == grid[0].size() - 1) {
        islated = false;
    }
    int num = 1;
    while (!que.empty()) {
        pair<int, int> tempIndex = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = tempIndex.first + direction[i][0];
            int nextY = tempIndex.second + direction[i][1];
            if (nextX < 0 || nextX >= grid.size() || nextY < 0 ||
                nextY >= grid[0].size()) {
                continue;
            }
            if (grid[nextX][nextY] == 1 && visited[nextX][nextY] == false) {
                // 判断是否在边界区域
                if (nextX == 0 || nextX == grid.size() - 1 || nextY == 0 ||
                    nextY == grid[0].size()) {
                    islated = false;
                }
                visited[nextX][nextY] = true;
                que.push({nextX, nextY});
                num++;
            }
        }
    }

    if (islated) {
        return num;
    } else {
        return 0;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> grid(N, vector<int>(M, 0));
    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }
    // bfs中如果扩散到 边缘 则不算入孤岛面积 返回0
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (grid[i][j] == 1 && visited[i][j] == false) {
                result += bfs(grid, visited, i, j);
            }
        }
    }
    cout << result << endl;
    return 0;
}
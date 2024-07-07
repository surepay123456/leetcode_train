#include <bits/stdc++.h>

#include <functional>
#include <initializer_list>
#include <iostream>
#include <queue>
#include <unordered_set>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
auto hash_function = [](const pair<int, int>& o) {
    return hash<int>()(o.first) ^ hash<int>()(o.second);
};
unordered_set<pair<int, int>, decltype(hash_function)> hashSet(0,
                                                               hash_function);
bool bfs(vector<vector<int>>& grid, int curX, int curY,
         vector<vector<bool>> visited) {
    queue<pair<int, int>> que;
    que.push(make_pair(curX, curY));
    visited[curX][curY] = true;
    bool reachLeft = false;
    bool reachRight = false;
    if (curX == 0 || curY == 0) {
        reachLeft = true;
    }

    if (curX == grid.size() - 1 || curY == grid[0].size()) {
        reachRight = true;
    }

    if (reachLeft && reachRight) {
        return true;
    }
    while (!que.empty()) {
        pair<int, int> tempIndex;
        tempIndex = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = tempIndex.first + direction[i][0];
            int nextY = tempIndex.second + direction[i][1];

            // 越界
            if (nextX >= grid.size() || nextX < 0 || nextY >= grid[0].size() ||
                nextY < 0) {
                continue;
            }
            // 不满足扩散规则 即高度大于源高度
            if (grid[nextX][nextY] > grid[tempIndex.first][tempIndex.second]) {
                continue;
            }
            // 扩散到了已经满足要求的节点
            if (hashSet.count({nextX, nextY})) {
                return true;
            }

            // 判断是否到达两个边界
            if (nextX == 0 || nextY == 0) {
                reachLeft = true;
            }

            if (nextX == grid.size() - 1 || nextY == grid[0].size()) {
                reachRight = true;
            }

            if (reachLeft && reachRight) {
                return true;
            }

            // 扩展节点 加入已访问节点中
            if (visited[nextX][nextY] == false) {
                que.emplace(nextX, nextY);
            }
        }
    }
    return false;
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

    // 大西洋水流问题statements 解决的是一个节点能否扩散到 两个边界的问题
    // 为了避免重复，用一个hash表来存储可以到达两个边界的坐标信息
    vector<vector<int>> results;
    for (int i = 0; i < grid.size(); i++) {
        for (int j = 0; j < grid[0].size(); j++) {
            if (bfs(grid, i, j, visited)) {
                results.push_back(vector<int>(i, j));
            }
        }
    }

    for (auto vec : results) {
        for (auto num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
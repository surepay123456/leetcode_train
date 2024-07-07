#include <bits/stdc++.h>

#include <iostream>
#include <queue>
#include <stack>
#include <utility>
#include <vector>
using namespace std;

vector<vector<int>> direction = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
void dfs(vector<vector<int>>& map, int curX, int curY,
         vector<vector<bool>>& visited) {
    for (int i = 0; i < 4; i++) {
        int nextX = curX + direction[i][0];
        int nextY = curY + direction[i][1];
        if (nextX >= map.size() || nextX < 0 || nextY >= map[0].size() ||
            nextY < 0) {
            continue;
        }
        if (map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
            visited[nextX][nextY] = true;
            dfs(map, nextX, nextY, visited);
        }
    }
}

void bfs(vector<vector<int>>& map, int curX, int curY,
         vector<vector<bool>>& visited) {
    queue<pair<int, int>> que;
    que.push(make_pair(curX, curY));
    while (!que.empty()) {
        pair<int, int> tempIndex;
        tempIndex = que.front();
        que.pop();
        for (int i = 0; i < 4; i++) {
            int nextX = tempIndex.first + direction[i][0];
            int nextY = tempIndex.second + direction[i][1];
            if (nextX >= map.size() || nextX < 0 || nextY >= map[0].size() ||
                nextY < 0) {
                continue;
            }
            if (map[nextX][nextY] == 1 && !visited[nextX][nextY]) {
                visited[nextX][nextY] = true;
                que.push(make_pair(nextX, nextY));
            }
        }
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> map(N, vector<int>(M, 0));

    vector<vector<bool>> visited(N, vector<bool>(M, false));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> map[i][j];
        }
    }

    // 从map中为1 并且未被访问的节点开始 深搜 搜到的岛屿标记为已经访问
    int result = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (!visited[i][j] && map[i][j] == 1) {
                result++;
                visited[i][j] = true;
                dfs(map, i, j, visited);
            }
        }
    }

    cout << result << endl;
    return 0;
}
#include <bits/stdc++.h>

#include <deque>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> m >> n;
    vector<string> map;
    string str;
    int startX, startY;
    for (int i = 0; i < m; i++) {
        cin >> str;
        for (int j = 0; j < n; j++) {
            if (str[j] == 'A') {
                startX = i;
                startY = j;
            }
        }
        map.push_back(str);
    }

    vector<vector<bool>> visited =
        vector<vector<bool>>(m, vector<bool>(n, false));

    // 要求能探索的区域 BFS 来解决
    // 定义专门的扩散方式
    // 在下一点是否可以扩散：
    // 1.不超过边界区域
    // 2.该点没有炸弹
    // 3.visited = false
    // 4.雷区移动安全法则

    deque<std::pair<int, int>> que;
    visited[startX][startY] = true;
    que.push_back(std::make_pair(startX, startY));
    int direction[8][2] = {{-1, 0},  {1, 0},  {0, -1}, {0, 1},
                           {-1, -1}, {-1, 1}, {1, -1}, {1, 1}};
    std::pair<int, int> tempNode;
    int result = 0;
    while (!que.empty()) {
        tempNode = que.front();
        int curX = tempNode.first;
        int curY = tempNode.second;
        que.pop_front();
        result++;
        for (int i = 0; i < 8; i++) {
            int nextX = curX + direction[i][0];
            int nextY = curY + direction[i][1];
            // 1.边界条件
            if (nextX < 0 || nextX >= m || nextY < 0 || nextY >= n) continue;
            // 2.扩展阶段不能有炸弹
            if (map[nextX][nextY] == '*') continue;
            // 3.扩展节点未被访问过
            if (visited[nextX][nextY]) continue;
            // 4.雷区移动安全法则
            // 注意边界区域以外都是雷
            //纵向扩展 扩展后的节点左右不能有炸弹
            if (i <= 1) {
                if (nextY + 1 >= n || map[nextX][nextY + 1] == '*') continue;
                if (nextY - 1 < 0 || map[nextX][nextY - 1] == '*') continue;
                visited[nextX][nextY] = true;
                que.push_back(std::make_pair(nextX, nextY));
            }
            //横向扩展 扩展后的节点上下不能有炸弹
            else if (i >= 2 && i <= 3) {
                if (nextX - 1 < 0 || map[nextX - 1][nextY] == '*') continue;
                if (nextX + 1 >= m || map[nextX + 1][nextY] == '*') continue;
                visited[nextX][nextY] = true;
                que.push_back(std::make_pair(nextX, nextY));
            }
            //斜向扩展 斜向的两个方向不能有炸弹
            else {
                if (map[nextX][curY] == '*') continue;
                if (map[curX][nextY] == '*') continue;
                visited[nextX][nextY] = true;
                que.push_back(std::make_pair(nextX, nextY));
            }
        }
    }
    cout << result << endl;
    return 0;
}
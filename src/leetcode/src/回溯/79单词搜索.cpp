#include <bits/stdc++.h>

#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    bool exist(vector<vector<char>>& board, string word) {
        // 如果当前的序列 满足word 前部分顺序 则进行回溯 方向扩展
        // 先遍历每个字符看看是否有可能是起点
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool>> visited =
            vector<vector<bool>>(m, vector<bool>(n, false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                // 如果当前的字符是起点
                if (board[i][j] == word[0]) {
                    visited = vector<vector<bool>>(m, vector<bool>(n, false));
                    // 进行回溯
                    visited[i][j] = true;
                    if (backtracing(board, word, visited, i, j, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

   private:
    int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    bool backtracing(vector<vector<char>>& board, string word,
                     vector<vector<bool>>& visited, int x, int y, int k) {
        // 如果当前的字符不等于word的第k个字符
        if (board[x][y] != word[k]) {
            return false;
        }
        // 如果当前的字符等于word的最后一个字符
        if (k == word.size() - 1) {
            return true;
        }

        // 进行回溯 如果返回true则立即全部返回， 不再回溯了
        // 在每次回溯的时候 设置visited，回溯出来的时候 设置为false
        for (int i = 0; i < 4; i++) {
            // 判断边界条件
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            if (0 <= nextX && nextX < board.size() && 0 <= nextY &&
                nextY < board[0].size()) {
                // visited 矩阵来标记已经访问过 不然程序不会停止
                if (visited[nextX][nextY] == true) continue;
                visited[nextX][nextY] = true;
                if (backtracing(board, word, visited, nextX, nextY, k + 1)) {
                    return true;
                }
                visited[nextX][nextY] = false;
            }
        }

        return false;
    }
};

int main() {
    vector<vector<char>> board = {
        {'A', 'B', 'C', 'E'}, {'S', 'F', 'C', 'S'}, {'A', 'D', 'E', 'E'}};
        
    string word{"ABCCED"};
    Solution solution;
    if (solution.exist(board, word)) {
        cout << "true" << endl;
    }

    return 0;
}

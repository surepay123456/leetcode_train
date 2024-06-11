#include <vector>

#include "header.h"

class Solution {
   public:
    void solve(vector<vector<char>>& board) {
        int m = board.size();
        int n = board[0].size();
        //遍历边界区域
        for (int i = 0; i < m; i++) {
            if (board[i][n - 1] == 'O') {
                board[i][n - 1] = 'A';
                dfs(board, i, n - 1);
            }
        }
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                board[i][0] = 'A';
                dfs(board, i, 0);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                board[0][i] = 'A';
                dfs(board, 0, i);
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[m - 1][i] == 'O') {
                board[m - 1][i] = 'A';
                dfs(board, m - 1, i);
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'A')
                    board[i][j] = 'O';
                else if (board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
    }

   private:
    int direction[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    void dfs(vector<vector<char>>& board, int x, int y) {
        for (int i = 0; i < 4; i++) {
            int nextX = x + direction[i][0];
            int nextY = y + direction[i][1];
            //判断是否超出边界
            if (nextX < 0 || nextX >= board.size() || nextY < 0 ||
                nextY >= board[0].size())
                continue;
            if (board[nextX][nextY] == 'O') {
                board[nextX][nextY] = 'A';
                dfs(board, nextX, nextY);
            }
        }
    }
};
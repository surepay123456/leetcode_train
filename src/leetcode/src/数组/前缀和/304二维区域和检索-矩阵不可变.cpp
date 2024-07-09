#include <bits/stdc++.h>
#include <dbg.h>

#include <iostream>
#include <vector>
using namespace std;

class NumMatrix {
   public:
    NumMatrix(vector<vector<int>>& matrix) {
        // 构造矩阵
        matrixSum.resize(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                dbg(matrix[i][j]);
                matrixSum[i + 1][j + 1] = matrix[i][j] + matrixSum[i][j + 1] +
                                          matrixSum[i + 1][j] - matrixSum[i][j];
            }
        }
        dbg(matrixSum);
        // 矩阵前缀和方法
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        int result = 0;
        dbg(matrixSum[row2 + 1][col2 + 1]);
        dbg(matrixSum[row1 + 1][col2 + 1]);
        dbg(matrixSum[row1][col1]);
        dbg(matrixSum[row2 + 1][col1 + 1]); 
        result += matrixSum[row2 + 1][col2 + 1] - matrixSum[row1 - 1 + 1][col2 + 1];
        result += matrixSum[row1][col1] - matrixSum[row2 + 1][col1 - 1 + 1];
        return result;
    }

   private:
    vector<vector<int>> matrixSum;
};

int main() {
    // vector<vector<int>> matrix = {{3, 0, 1, 4, 2},
    //                               {5, 6, 3, 2, 1},
    //                               {1, 2, 0, 1, 5},
    //                               {4, 1, 0, 1, 7},
    //                               {1, 0, 3, 0, 5}};
    vector<vector<int>> matrix = {{-4, -5}};
    dbg(matrix);
    NumMatrix numMatrix(matrix);
    cout << numMatrix.sumRegion(0, 0, 0, 1);
    return 0;
}
/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */
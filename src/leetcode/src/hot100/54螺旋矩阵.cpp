#include <bits/stdc++.h>
#include <dbg.h>
#include <unistd.h>

#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if (matrix.empty()) {
            return {};
        }
        int l = 0, r = matrix[0].size() - 1, t = 0, b = matrix.size() - 1;
        vector<int> ans;
        while (true) {
            for (int i = l; i <= r; i++) {
                ans.push_back(matrix[t][i]);
            }
            if (++ t> b) {
                break;
            }
            for (int i = t; i <= b; i++) {
                ans.push_back(matrix[i][r]);
            }
            if (--r < l) {
                break;
            }
            for (int i = r; i >= l; i--) {
                ans.push_back(matrix[b][i]);
            }
            if (--b < t) {
                break;
            }
            for (int i = b; i >= t; i--) {
                ans.push_back(matrix[i][l]);
            }
            if (++l > r) {
                break;
            }
        }
        return ans;
    }
};

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    Solution solution;
    dbg(solution.spiralOrder(matrix));
    return 0;
}

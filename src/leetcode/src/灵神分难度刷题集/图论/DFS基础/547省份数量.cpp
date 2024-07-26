#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool> visited(isConnected.size(), false);
        // isConnectedp[i][j] 表示连通的
        int result = 0;
        for (int i = 0; i < isConnected.size(); i++) {
            if (visited[i] != true) {
                result++;
                dfs(visited, i, isConnected);
            }
        }
        return result;
    }

   private:
    void dfs(vector<bool>& visited, int index,
             vector<vector<int>>& isConnected) {
        visited[index] = true;
        for (int i = 0; i < isConnected[index].size(); i++) {
            int next = isConnected[index][i];
            if (next == 0) {
                continue;
            }
            if (index != i && visited[i] != true) {
                dfs(visited, i, isConnected);
            }
        }
    }
};

int main() {
    vector<vector<int>> isConnected = {{1, 0, 0}, {0, 1, 0}, {0, 0, 1}};
    Solution solution;
    cout << solution.findCircleNum(isConnected) << endl;
    return 0;
}
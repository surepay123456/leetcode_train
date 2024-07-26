#include <bits/stdc++.h>
#include <vector>
using namespace std;

class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        //先进到0号房间拿到钥匙 0号门的钥匙代表与其他门的连通性
        vector<bool> visited(rooms.size());
        dfs(rooms, visited, 0);
        for (int i = 0; i < visited.size(); i ++) {
            if (!visited[i]) {
                return false;
            }
        }
        return true;

    }
private:
    void dfs(vector<vector<int>> & rooms, vector<bool> &visited, int start){
        visited[start] = true;
        for (int i = 0;  i < rooms[start].size(); i ++) {
            if (visited[rooms[start][i]]) {
                continue;
            }
            dfs(rooms, visited, rooms[start][i]);
        }
    }
};
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // 如果在同一个集合里面则不需要连接
        father.resize(1006);
        for (int i = 0; i < father.size(); i++) {
            father[i] = i;
        }

        for (int i = 0; i < edges.size(); i ++) {
            if(isSame(edges[i][0], edges[i][1])){
                return edges[i];
            }
            join(edges[i][0], edges[i][1]);
        }
        return {};
    }
private:
    vector<int> father;
    int find(int cur){
        int u  = cur;
        while (u != father[u]) {
            u = father[u];
        } 
        father[cur] = u;
        return u;
    }
    bool isSame(int u , int v){
        u = find(u);
        v = find(v);
        if (u == v) {
            return true;
        }
        else {
            return false;
        }
    }
    void join(int u, int v){
        u = find(u);
        v = find(v);
        if (u == v) {
            return;
        }
        else {
            father[v] = u;
        }
    }
};

int main(){
    vector<vector<int>> edges = {{1, 2}, {1, 3}, {2, 3}};
    Solution solution;
    vector<int> result = solution.findRedundantConnection(edges);
    for (auto & i       : result) {
        cout << i<<endl; 
    }
    return 0;
}
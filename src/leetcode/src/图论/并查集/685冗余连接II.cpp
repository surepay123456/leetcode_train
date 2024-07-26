#include <bits/stdc++.h>

#include <vector>
using namespace std;

class Solution {
   public:
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        vector<int> inDegree(edges.size(), 0);
        for (int i = 0; i < edges.size(); i++) {
            inDegree[edges[i][1]]++;
            if (inDegree[edges[i][1]] == 2) {
                
            }
        }
    }
};
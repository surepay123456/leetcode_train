#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

bool compare(vector<int> &a, vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        //矩阵的宽小于等于w
        //先按x大小排序
        sort(points, compare);
        //
        // 贪心一波
        
    }
};
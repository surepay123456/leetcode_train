#include <algorithm>
#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <dbg.h>
using namespace std;

bool compare(vector<int> &a, vector<int> b){
    return a[0] < b[0];
}

class Solution {
public:
    int minRectanglesToCoverPoints(vector<vector<int>>& points, int w) {
        //矩阵的宽小于等于w
        //先按x大小排序
        sort(points.begin(), points.end() , compare);
        // dbg(points);
        //
        // 贪心一波
        int num = 0;
        // 覆盖区间写法
        int right = -1;
        for (int i = 0; i < points.size(); i ++) {
            if (right < points[i][0]) {
                right = points[i][0] + w;
                num ++;
            }
        }
        return num;
        
    }
};

int main(){
    vector<vector<int>> points = {{0,0},{2,1},{2,2},{3,3},{4,4},{5,5},{6,6}};
    int w = 2;
    Solution solution;
    cout << solution.minRectanglesToCoverPoints(points, w) << endl;
    return 0;
}
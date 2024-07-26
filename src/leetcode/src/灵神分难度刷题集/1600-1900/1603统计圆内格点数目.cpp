#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int countLatticePoints(vector<vector<int>>& circles) {
        auto compare = [](vector<int> a, vector<int> b) { return a[2] > b[2]; };
        sort(circles.begin(), circles.end(), compare);
        int cnt = 0;

        for (int i = 0; i <= 201; i++) {
            for (int j = 0; j <= 201; j++) {
                for (int k = 0; k < circles.size(); k++) {
                    int x = circles[k][0];
                    int y = circles[k][1];
                    int r = circles[k][2];
                    if ((x - i) * (x - i) + (y - j) * (y - j) <= r * r) {
                        cnt++;
                        break;
                    }
                }
            }
        }
        return cnt;
    }
};

int main() {
    vector<vector<int>> circles = {{2, 2, 2}, {3, 4, 1}};

    Solution solution;
    cout << solution.countLatticePoints(circles);
    return 0;
}
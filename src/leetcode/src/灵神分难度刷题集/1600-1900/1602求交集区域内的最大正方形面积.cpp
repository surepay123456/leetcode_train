#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

class Solution {
   public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft,
                                vector<vector<int>>& topRight) {
        //
        long long result = 0;
        for (int i = 0; i < bottomLeft.size(); i++) {
            auto& b1 = bottomLeft[i];
            auto& t1 = topRight[i];
            for (int j = i + 1; j < bottomLeft.size(); j++) {
                auto& b2 = bottomLeft[j];
                auto& t2 = topRight[j];
                long long height = min(t1[1], t2[1]) - max(b1[1], b2[1]);
                long long width = min(t1[0], t2[0]) - max(b1[0], b2[0]);
                if (height <= 0 || width <= 0) {
                    continue;
                }
                long long l = min(height, width);
                result = max(result, l * l);
            }
        }
        return result;
    }
};

int main() {
    vector<vector<int>> bottomLeft = {{1, 1}, {2, 2}, {3, 1}};
    vector<vector<int>> topRight = {{3, 3}, {4, 4}, {6, 6}};
    Solution solution;
    cout << solution.largestSquareArea(bottomLeft, topRight);
    return 0;
}
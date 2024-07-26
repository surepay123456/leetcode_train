#include <bits/stdc++.h>
#include <dbg.h>

#include <algorithm>
#include <functional>
#include <vector>
using namespace std;

class Solution {
   public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        // 排个序
        auto func = [](vector<int>& a, vector<int>& b) { return a[0] < b[0]; };
        sort(intervals.begin(), intervals.end(), func);
        dbg(intervals);
        vector<vector<int>> ans;
        for (int i = 0; i < intervals.size(); i++) {
            int left = intervals[i][0];
            int rightMax = intervals[i][1];
            dbg(intervals[i]);
            while (i + 1 < intervals.size()) {
                i++;
                if (intervals[i][0] <= rightMax) {
                    rightMax = max(rightMax, intervals[i][1]);
                } else {
                    i --;
                    break;
                }
                dbg(intervals[i]);
            }
            ans.push_back({left, rightMax});
        }
        return ans;
    }
};
int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};
    Solution solution;
    dbg(solution.merge(intervals));
    return 0;
}
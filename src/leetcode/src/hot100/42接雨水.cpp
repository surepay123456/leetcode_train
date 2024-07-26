#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Solution {
   public:
    int trap(vector<int>& height) {
        // 前缀，后缀
        // min(leftMax, rightMax) - height
        vector<int> leftMax(height.size(), 0);
        vector<int> rightMax(height.size(), 0);
        for (int i = 1; i < height.size(); i++) {
            leftMax[i] = max(leftMax[i - 1], height[i - 1]);
        }
        for (int i = height.size() - 2; i >= 0; i--) {
            rightMax[i] = max(rightMax[i + 1], height[i + 1]);
        }
        int ans = 0;
        for (int i = 0; i < height.size(); i++) {
            if (min(leftMax[i], rightMax[i]) > height[i]) {
                ans += min(leftMax[i], rightMax[i]) - height[i];
            }
        }
        return ans;
    }
};

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    Solution solution;
    cout << solution.trap(height) << endl;
    return 0;
}
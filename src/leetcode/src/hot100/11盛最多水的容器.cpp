#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
#include <dbg.h>
using namespace std;

class Solution {
   public:
    int maxArea(vector<int>& height) {
        // (j - i) * min(height[i], height[j])
        int p = 0;
        int q = height.size() - 1;
        int maxArea = 0;
        while (p < q) {
            // dbg(p, q, min(height[q] * (q - p), height[p] * (q - p)));
            if (height[p] > height[q]) {
                maxArea = max(maxArea, height[q] * (q - p));
                q--;
            } 
            // else if (height[p] == height[q]) {
            //     maxArea = max(maxArea, height[q] * (q - p));
            //     break;
            else {
                maxArea = max(maxArea, height[p] * (q - p));
                p++;
            }
            // dbg(p, q, maxArea);
        }
        return maxArea;
    }
};

int main(){
    vector<int> height = {1,3,2,5,25,24,5};
    Solution solution;
    cout << solution.maxArea(height) << endl;
    return 0;
}
#include <bits/stdc++.h>

#include <algorithm>
#include <cmath>
using namespace std;

class Solution {
   public:
    int findBestValue(vector<int>& arr, int target) {
        // 大于value的值变成value
        sort(arr.begin(), arr.end());
        int sum = 0;
        for (auto& i : arr) {
            sum += i;
        }
        int L = abs(sum - target);
        if (L == 0) {
            return arr[arr.size() - 1];
        }

        // 从后先前 凑出来减小 L 的
        

        // [3, 4 ,9]   10  16 
    }
};
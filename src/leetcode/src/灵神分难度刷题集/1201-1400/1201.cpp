#include <algorithm>
#include <bits/stdc++.h>
#include <climits>
using namespace std;

class Solution {
public:
    double average(vector<int>& salary) {
        // 记录最大和最小 最后输出结果减去就是了
        int maxNum = INT_MIN;
        int minNum = INT_MAX;
        int sum = 0;
        for (int i = 0; i < salary.size(); i++) {
            sum += salary[i];
            maxNum = max(maxNum, salary[i]);
            minNum = min(minNum, salary[i]); 
        } 
        return double(sum - maxNum - minNum)/(salary.size() - 2) ;
    }
};
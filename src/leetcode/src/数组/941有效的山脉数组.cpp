#include <bits/stdc++.h>
using namespace std;

class Solution {
   public:
    bool validMountainArray(vector<int>& arr) {
        bool isIncreased = true;
        int times = 0;
        int riseTimes = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (isIncreased) {
                //检测到下降， 判断是否是第一次下降
                if (arr[i] > arr[i + 1]) {
                    if (times == 0) {
                        isIncreased = false;
                        times++;
                        continue;
                    } else {
                        return false;
                    }
                } else if (arr[i] == arr[i + 1]) {
                    return false;
                }
                riseTimes ++; 
                
            } else {
                if (arr[i + 1] >= arr[i]) {
                    return false;
                }
            }
        }
        // 必须同时有上升和下降
        if (isIncreased || !riseTimes) return false;
        
        return true;
    }
};
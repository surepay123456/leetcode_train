#include <bits/stdc++.h>

#include <cstdio>
#include <string>
#include <vector>
using namespace std;
class Solution {
   public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        // 最大子集的长度
        // strs = ["10", "0001", "111001", "1", "0"], m = 5, n = 3
        // 1、0的数量不超过5， 3
        // 转换为现在有1的容量为5 0的容量为3 要尽可能多装子集
        // 多维的背包
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        // dp数组
        for (int i = 0; i < strs.size(); i++) {
            int onesNum = caculateOnes(strs[i]);
            int zerosNum = caculateZeros(strs[i]);
            for (int j = m; j >= zerosNum; j--) {
                for (int k = n; k >= onesNum; k--) {
                    dp[j][k] = max(dp[j][k], dp[j - zerosNum][k - onesNum] + 1);
                }
            }
        }
        return dp[m][n];
    }

   private:
    int caculateOnes(string& str) {
        int count = 0;
        for (auto& ch : str) {
            if (ch == '1') {
                count++;
            }
        }
        return count;
    }

    int caculateZeros(string& str) {
        int count = 0;
        for (auto& ch : str) {
            if (ch == '0') {
                count++;
            }
        }
        return count;
    }
};
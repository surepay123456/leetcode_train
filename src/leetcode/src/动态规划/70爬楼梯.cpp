#include "../../include/header.h"
#include <dbg.h>

class Solution {
public:
    int climbStairs(int n) {
        //使用数据压缩递推的方式
        // dp[n] = dp[n - 1] + dp[n - 2];

        if(n == 1) return 1;
        if(n == 2) return 2;

        int pre = 2;
        int prepre = 1;
        int ans = 0;
        for(int i = 3; i <= n; i++){
           ans = pre + prepre;
           prepre = pre;
           pre = ans; 
        }
        return ans;
// n = 4
    }
};
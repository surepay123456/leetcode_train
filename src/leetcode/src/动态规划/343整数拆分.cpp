#include <header.h>
#include <vector>

class Solution {
public:
    int integerBreak(int n) {
        // 拆分原则 dp[2] = 1; dp[3] 1 2; dp[4] 1 3; 2 2; 
        // dp[n]能被怎样拆分？  i * (n - i)  i * dp[n - i] 第一个是拆分为两个数不利用之前的最优递推数组 
        // 第二个 表示三个及以上的拆分  
        // 为什么不dp[i] * dp[n - i]？ 这种情况其实已经被包含在第二个里面

        //初始化dp矩阵
        //最少要拆分2 拆分1没有意义 这里先写这个 后面根据递推来初始化
        // i : dp index ; j : 拆分索引

        // int dp[n + 1] = {0};
        vector<int> dp(n + 1, 0);
        dp[2] = 1;
        for(int i = 3; i <= n; i ++){
            for(int j = 1; j <= i / 2; j ++){
                dp[i] = max(dp[i], max(j * (i - j), j * dp[i - j]));
            }
        }  
        return  dp[n];
    }
};
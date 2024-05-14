#include <header.h>

class Solution {
public:
    int numTrees(int n) {
        
        // dp[i] 表示i个节点的二叉搜索树的个数
        // 将i当做根节点，那么n个数就被分割到左右子树里面去 总的个数 = 左子树的个数 * 右子树的个数 
        // n == 3 
        if(n == 0) return 0;
        int dp[n + 1];
        dp[0] = 1;
        // dp[i] = sum(i 0 -> n - 1){ dp[i - 0] * dp[n - 1 - i]} 
        for(int j = 1; j <= n; j++){
           dp[j] = 0;
           for(int i = 0; i <= j - 1; i++){
                dp[j] += dp[i - 0] * dp[j - 1 - i]; // j == 1; j == 2;
           } 
        }
        return dp[n];
        

    }
};
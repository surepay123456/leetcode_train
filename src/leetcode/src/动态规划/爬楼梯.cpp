#include <bits/stdc++.h>

#include <iostream>
#include <vector>

using namespace std;

int main() {
    int m, n;
    cin >> n >> m;
    // n 阶台阶 一次可以走 1 - m 台阶

    // 1 2 1 与 2 1 1是两种不同的方法
    // 则此背包求的是排列
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 0; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            if (i >= j) {
                dp[i] += dp[i - j];
            }
        }
    }
    cout << dp[n] << endl;
    return 0;
}
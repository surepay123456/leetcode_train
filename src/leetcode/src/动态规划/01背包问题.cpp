
// 放物品i 与 不放物品i 两种情况 状态转移

#include <bits/stdc++.h>

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int num, bag_weight;
    cin >> num >> bag_weight;
    vector<int> weights(num);
    vector<int> costs(num);
    for (int i = 0; i < num; i++) {
        cin >> weights[i];
    }
    for (int i = 0; i < num; i++) {
        cin >> costs[num];
    }
    for (auto& i : weights) {
        cout << i << " " << endl;
    }
    for (auto& i : costs) {
        cout << i << " " << endl;
    }
    vector<vector<int>> dp(num, vector<int>(bag_weight + 1, 0));
    // 初始化第一排
    //  dp[i][j] 是指 在前i个物品中选择，背包容量为j，能装到的最大价值
    //  如果装i 则价值为 已有容量j减去i的大小， 并且在前i - 1个物品中选择
    //  如果不装i 则价值 为容量j的情况下 在前i - 1个物品中选择
    for (int i = weights[0]; i <= bag_weight; i++) {
        dp[0][i] = costs[0];
    }
    for (int i = 1; i < num; i++) {
        for (int j = 1; j <= bag_weight; j++) {
            if (weights[i] > j)
                dp[i][j] = dp[i - 1][j];
            else {
                dp[i][j] =
                    max(dp[i - 1][j], dp[i - 1][j - weights[i]] + costs[i]);
            }
        }
    }
    cout <<  dp[num - 1][bag_weight] << endl;
    return 0;
}
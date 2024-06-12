#include <bits/stdc++.h>

#include <iostream>
#include <iterator>
#include <vector>
using namespace std;

int main() {
    int N, bag_weight;
    cin >> N >> bag_weight;
    vector<int> weights(N, 0);
    vector<int> costs(N, 0);
    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> costs[i];
    }

    vector<int> dp(bag_weight + 1);

    for (int i = 0; i < N; i++) {
        for (int j = weights[i]; j <= bag_weight; j++) {
            dp[j] = max(dp[j], dp[j - weights[i]] + costs[i]);
        }
    }
    cout << dp[bag_weight];
    return 0;
}
#include <bits/stdc++.h>

#include <cstring>
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

    vector<int> dp(bag_weight + 1, 0);
    for (int i = 0; i < num; i++) {
        for (int j = bag_weight; j >= weights[i]; j--) {
            dp[j] = max(dp[j], dp[j - weights[i]] + costs[i]);
        }
    }
    cout << dp[bag_weight] << endl;
    return 0;
}
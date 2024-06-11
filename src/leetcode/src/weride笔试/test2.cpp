#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    int N, T;
    int result1 = 0;
    int result2 = 0;
    int choice = -1;
    std::cin >> N >> T;
    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    for (int i = 0; i < N; i++) {
        std::cin >> b[i];
    }

    // 两种情况的背包问题  背包容量为T 题的权重都为1
    // 既然题目权重都为1 转化为 贪心问题 先做题目时间少的
    std::sort(a.begin(), a.end());
    std::sort(b.begin(), b.end());

    // case1 带一台电脑
    int tempT = T;

    for (int i = 0; i < N; i++) {
        if (tempT >= a[i]) {
            result1++;
            tempT -= a[i];
        }

        else {
            break;
        }
    }

    // case2 带三台电脑
    tempT = T;
    for (int i = 0; i < N; i++) {
        if (tempT >= b[i]) {
            result2++;
            tempT -= b[i];
        }

        else {
            break;
        }
    }

    if (result1 >= result2) {
        choice = 1;
        std::cout << result1 << std::endl;
    } else {
        choice = 3;
        std::cout << result2 << std::endl;
    }

    std::cout << choice << std::endl;
    return 0;
}
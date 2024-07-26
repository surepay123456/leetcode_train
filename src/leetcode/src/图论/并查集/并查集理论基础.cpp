#include <bits/stdc++.h>

#include <ratio>
#include <vector>
using namespace std;

int n = 1005;
vector<int> father = vector<int>(n, 0);

// 初始的时候都指向自己
void init() {
    for (int i = 0; i < n; i++) {
        father[i] = i;
    }
}

// 寻根过程
int find(int cur) {
    int root = cur;
    while (cur != father[cur]) {
        cur = father[cur];
    }
    return father[root] = cur;
}

// 查看是否同根
bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return true;
    } else {
        return false;
    }
}

// 加入新的连接  v -> u 入并查集
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return;
    } else {
        father[v] = u;
    }
}
#include <bits/stdc++.h>

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

vector<int> father;

int find(int u) {
    int cur = u;
    while (father[u] != u) {
        u = father[u];
    }
    father[cur] = u;
    return u;
}

// u <- v
void join(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return;
    } else {
        father[v] = u;
    }
}

bool isSame(int u, int v) {
    u = find(u);
    v = find(v);
    if (u == v) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int N, M;
    cin >> N >> M;
    father.resize(N + 1);
    for (int i = 0; i < N; i++) {
        father[i] = i;
    }
    int s, t;
    for (int i = 0; i < M; i++) {
        cin >> s >> t;
        join(s, t);
    }
    int source, destination;
    cin >> source >> destination;
    if (isSame(source, destination)) {
        cout << 1 << endl;
    }
    else {
        cout << 0 << endl;
    }
    return 0;
    //
}
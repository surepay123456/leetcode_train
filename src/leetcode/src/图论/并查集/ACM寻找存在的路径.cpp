#include <bits/stdc++.h>
#include <iostream>
#include <vector>
using namespace std;

// 判断是否连通
int main(){
    int N, M;
    cin>> N >> M;
    vector<vector<int>> edges(M,  vector<int>(2, 0));
    for ( int i = 0; i < M; i++) {
        cin >> edges[i][0] >> edges[i][1];
    }
    // 节点编号从1到N 即对应关系
    vector<int> father(N + 1, 0);
    for (int i = 1; i < N + 1; i++) {
        father[i] = i;
    }
    int source, target;
    cin >> source >> target;
    

    //遍历edges 建立并查集
    // 1. 判断father是不是一样的 
    // 2. 


}
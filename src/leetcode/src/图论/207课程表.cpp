#include <stack>
#include <vector>

#include "header.h"

class Solution {
   public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // 入度表
        // [a, b] 要学a 必须先学b 即图的连接是 b -> a
        vector<vector<int>> graph(numCourses);  //表示当前节点指向哪些节点
        vector<int> indegree(numCourses, 0);
        //入度表 表示指向当前节点其他节点的数目

        //建立图关系 和入度表
        int numEdge = prerequisites.size();
        for (int i = 0; i < numEdge; i++) {
            vector<int> edge = prerequisites[i];
            graph[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        //进行拓扑排序
        //先在队列中加入 入度为0的节点
        // 准则 队列中的节点都是 当前入度为1的节点
        queue<int> topoOrder;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0) topoOrder.push(i);
        }

        // 拓扑排序 其实是模拟课程表学习的顺序 先学了入度为0 的课程，
        // 学完了学新的入度为0的课程
        int learnedNum = 0;
        while (!topoOrder.empty()) {
            int node = topoOrder.front();
            topoOrder.pop();
            learnedNum++;
            for (int i = 0; i < graph[node].size(); i++) {
                int inNode = graph[node][i];
                indegree[inNode]--;
                if (indegree[inNode] == 0) topoOrder.push(inNode);
            }
        }

        //如果出现环的情况 证明 学习的课程数少于总的课程数
        if (learnedNum != numCourses) {
            return false;
        }

        return true;
    }
};
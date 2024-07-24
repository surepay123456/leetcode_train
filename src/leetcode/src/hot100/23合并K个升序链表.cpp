#include <bits/stdc++.h>

#include <cmath>
#include <queue>
#include <vector>
using namespace std;

struct doubleListNode {
    int val;
    doubleListNode* next;
    doubleListNode() : val(0), next(nullptr) {}
    doubleListNode(int x) : val(x), next(nullptr) {}
    doubleListNode(int x, doubleListNode* next) : val(x), next(next) {}
};

class Solution {
   public:
    doubleListNode* mergeKLists(vector<doubleListNode*>& lists) {
        auto cmp = [](const doubleListNode* a, const doubleListNode* b) {
            return a->val > b->val;
        };
        priority_queue<doubleListNode*, vector<doubleListNode*>, decltype(cmp)> pq(cmp);
        for (auto head : lists) {
            if (head) {
                pq.push(head);
            }
        }
        doubleListNode dummy{};
        auto cur = &dummy;
        while (!pq.empty()) {
            auto node = pq.top();
            pq.pop();
            if (node->next) {
                pq.push(node->next);
            }
            cur->next = node;
            cur = cur->next;
        }
        return dummy.next;
    }
};
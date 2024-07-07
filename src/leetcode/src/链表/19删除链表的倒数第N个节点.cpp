#include <bits/stdc++.h>
using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};
class Solution {
   public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        //扫描一遍完成 倒数第n个节点
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* p = dummyNode;
        ListNode* q = dummyNode;
        while (n--) {
            q = q->next;
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        ListNode* toDel = p->next;
        p ->next =p->next->next;
        delete toDel;
        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};
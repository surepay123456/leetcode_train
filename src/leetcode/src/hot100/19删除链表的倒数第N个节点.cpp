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
        // 双指针
        ListNode* dummptNode = new ListNode(0);
        dummptNode->next = head;
        ListNode* l = dummptNode;
        ListNode* r = dummptNode;
        while (n--) {
            r = r->next;
        }
        while (r->next) {
            l = l->next;
            r = r->next;
        }
        ListNode* toDel = l->next;
        l->next = l->next->next;
        delete toDel;
        return dummptNode->next;
    }
};
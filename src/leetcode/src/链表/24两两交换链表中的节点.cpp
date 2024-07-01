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
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummyNode = new ListNode(0);
        dummyNode->next = head;
        ListNode* cur = dummyNode;
        while (cur->next && cur->next->next) {
            ListNode* nextNode = cur->next;
            cur->next = cur->next->next;
            nextNode->next = nextNode->next->next;
            cur->next->next = nextNode;
            cur = nextNode;
        }
        ListNode* newHead = dummyNode->next;
        delete dummyNode;
        return newHead;
    }
};
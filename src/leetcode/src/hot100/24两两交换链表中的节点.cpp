#include <bits/stdc++.h>

#include <exception>
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
        ListNode* dummptNode = new ListNode();
        dummptNode->next = head;
        ListNode* cur = dummptNode;
        while (cur->next && cur->next->next) {
            ListNode* nextCur = cur->next->next;
            ListNode* temp = cur->next;
            cur->next = cur->next->next;
            temp->next = cur->next->next;
            cur->next->next =temp;
            cur = temp;
        }
        return dummptNode->next;
    }
};
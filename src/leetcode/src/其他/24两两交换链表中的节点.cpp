
#include "../include/header.h"

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* DummyHead = new ListNode(0);
        DummyHead->next = head;
        
        ListNode* nextnode = nullptr;
        ListNode* cur  = DummyHead;
        while(cur->next != nullptr && cur->next != nullptr){
            nextnode = cur->next;
            cur->next = cur->next->next;
            nextnode->next = cur->next->next;
            cur->next->next = nextnode;
            cur = nextnode;
        }
        return DummyHead->next;
    }
};

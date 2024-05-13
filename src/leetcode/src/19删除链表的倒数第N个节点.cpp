
#include "../include/header.h"

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
            //采用双指针的方法
            //添加虚拟头结点
            ListNode* dummpyHead = new ListNode(0);
            dummpyHead->next = head;
            
            ListNode* fast = dummpyHead;
            ListNode* slow = dummpyHead;
            
            while(n + 1){
               fast = fast->next;
               n--; 
            }

            while(fast != nullptr){
               slow = slow->next;
               fast = fast->next; 
            }

            slow->next = slow->next->next;
            return dummpyHead->next;
            
    }
};


#include "../include/header.h"

class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        
        // //两个指针 交换指向
        // ListNode* cur = head;
        // ListNode* pre = nullptr;
        // ListNode* next = nullptr;
        // while(cur){
        //     next = cur->next;
        //     cur->next = pre;
        //     pre = cur;
        //     cur = next;
            
        // }
        
        // return pre;

        // 递归方法

        if(!head || !head->next){
            return head;
        }

        ListNode* newHead = reverseList(head->next);

        head->next->next = head;
        head->next = nullptr;

        return newHead;

        
        

    }
};
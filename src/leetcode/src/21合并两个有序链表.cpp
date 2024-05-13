#include "../include/header.h"

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        
        ListNode* pre1 = nullptr;
        ListNode* pre2 = nullptr;

        if(!list1) return list2;
        if(!list2) return list1;
        

        if(list1->val >= list2->val){
            pre1 = list1;
            pre2 = list2;
        }
        else{
            pre1 = list2;
            pre2 = list1;
        }
        ListNode* ans = pre2;
        ListNode* last = nullptr; 
        while(pre1 != nullptr && pre2 != nullptr){
            // 找到小于等于pre1 的最后一个节
            while(pre1 != nullptr && pre2 != nullptr && pre2->val <= pre1->val ){
                last = pre2; 
                pre2 = pre2 -> next;
            }
            pre2 = last; 

            ListNode* next = pre2->next;
            pre2->next = pre1;
            pre1 = pre1->next;
            pre2->next->next = next;
            pre2 = pre2->next;
        }
        return ans;

    }
};
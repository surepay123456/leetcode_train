
#include "../include/header.h"

class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {

    int n1 = 0;
    int n2 = 0;
    ListNode* pre1 = l1;
    ListNode* pre2 = l2;
    
    while(pre1 != nullptr){
        n1++;
        pre1 = pre1->next;
    }

    while(pre2 !=nullptr){
        n2++;
        pre2 = pre2->next;
    }

    if(n2 > n1){
        swap(l1, l2);
        swap(n1, n2);
    }

    while(n1 > n2){
        l1->val = l1->val * pow(10, n1);
        n1--;
        l1 = l1 -> next;
    }
    
    while(n1 >= 0 && !l1 && !l2){
        l1->val = (l1->val + l2->val) * pow(10, n1);
        l1 = l1 -> next;
        l2 = l2 -> next;
        n1--;
    }

    return l1;

    


    }
};

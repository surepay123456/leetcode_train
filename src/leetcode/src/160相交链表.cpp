#include "../include/header.h"




 struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        

        //使用
        unordered_set<ListNode*> A_set;
    
        while(headA != NULL){
            // A_set.insert(headA->val);
            A_set.insert(headA);
            headA = headA->next;
        }

        while(headB != NULL){
            if(A_set.find(headB) != A_set.end()){
                return headB;
            }
            headB = headB->next;
        }

        return NULL;

        
        
    }
};
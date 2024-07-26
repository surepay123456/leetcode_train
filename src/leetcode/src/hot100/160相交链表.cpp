#include <bits/stdc++.h>
using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};
class Solution {
   public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *cur = nullptr;
        cur = headA;
        int lengthA = 0;
        while (!cur) {
            lengthA++;
            cur = cur->next;
        }
        cur = headB;
        int lengthB = 0;
        while (!cur) {
            cur = cur->next;
        }
        if (lengthA > lengthB) {
            int num = lengthA - lengthB;
            while (num) {
                headA = headA->next;
                num--;
            }
        } else {
            int num = lengthB - lengthA;
            while (num) {
                headB = headB->next;
                num--;
            }
        }
        while (headA &&headB) {
            if (headA->val == headB->val) {
                return headA;
            }
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};
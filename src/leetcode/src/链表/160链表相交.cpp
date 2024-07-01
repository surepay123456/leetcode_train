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
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        int lengthA = 0;
        int lengthB = 0;
        ListNode* curA = headA;
        ListNode* curB = headB;
        while (curA) {
            lengthA++;
            curA = curA->next;
        }
        while (curB) {
            lengthB++;
            curB = curB->next;
        }
        curA = headA;
        curB = headB;
        if (lengthA > lengthB) {
            int n = lengthA - lengthB;
            while (n--) {
                curA = curA->next;
            }
        } else {
            int n = lengthB - lengthA;
            while (n--) {
                curB = curB->next;
            }
        }
        while (curA && curB) {
            if (curA == curB) {
                return curA;
            } else {
                curA = curA->next;
                curB = curB->next;
            }
        }
        return nullptr;
    }
};
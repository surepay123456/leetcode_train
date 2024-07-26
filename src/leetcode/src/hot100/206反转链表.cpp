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
    ListNode* reverseList(ListNode* head) {
        /*
            1 -> 2 -> 3
            1 <- 2  3
            1 <- 2 <-3
        */
        ListNode* pre = nullptr;
        ListNode* cur = nullptr;
        ListNode* next = nullptr;

        cur = head;

        while (cur) {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
        }
        return pre;
    }
};
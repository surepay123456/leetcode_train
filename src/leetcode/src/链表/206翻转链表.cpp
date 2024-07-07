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
        // 1 -> 2 -> 3
        // pre  cur

        // 1 <- 2    3
        //      pre  cur
        if (head == nullptr) {
            return nullptr;
        }
        ListNode* dummpyNode = new ListNode(0);
        dummpyNode->next  = head;

        ListNode* pre = nullptr;
        ListNode* cur = nullptr;
        ListNode* next = nullptr;

        pre = dummpyNode->next;
        cur = pre ->next;

        while (cur != nullptr) {
            next = cur ->next;
            cur ->next = pre;
            pre = cur;
            cur = next;
        }
        dummpyNode->next->next = nullptr;
        dummpyNode->next = pre;

        return dummpyNode->next;
    }
};
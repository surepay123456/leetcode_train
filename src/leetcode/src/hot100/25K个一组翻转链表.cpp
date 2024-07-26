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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* dummpyNode = new ListNode();
        int n = 0;
        for (ListNode* cur = head; cur; cur = cur->next) {
            n++;
        }
        dummpyNode->next = head;
        ListNode* p0 = dummpyNode;
        ListNode* cur = head;

        for (; n >= k; n -= k) {
            ListNode* pre = nullptr;
            for (int i = 0; i < k; i++) {
                // 翻转
                // cur = p0->next;
                ListNode* nxt = cur->next;
                cur->next = pre;
                pre = cur;
                cur = nxt;
            }
            ListNode* nxt = p0->next;
            p0->next->next = cur;
            p0->next = pre;
            p0 = nxt;
        }
        return dummpyNode->next;
    }
};
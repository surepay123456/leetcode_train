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
    ListNode* detectCycle(ListNode* head) {
        // 入环的位置
        if (!head) {
            return nullptr;
        }
        ListNode* fast = head;
        ListNode* low = head;
        ListNode* index1 = nullptr;
        while (fast->next && fast->next->next) {
            fast = fast->next->next;
            low = low->next;
            if (fast == low) {
                index1 = fast;
                break;
            }
        }
        if (!index1) return nullptr;
        ListNode* cur = head;

        while (cur != index1) {
            cur = cur->next;
            index1 = index1->next;
        }
        return cur;
    }
};
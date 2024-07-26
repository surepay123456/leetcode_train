#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *low = head;
        while (fast && fast->next) {
            fast = fast->next->next;
            low = low->next;
            if (low == fast) {
                while (low != head) {
                    low = low->next;
                    head = head->next;
                } 
                return low;
            }
        }
        return nullptr;
        // fast x + y + n(circle) = 2 * (x + y)
    }
};
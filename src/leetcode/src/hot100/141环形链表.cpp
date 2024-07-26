#include <bits/stdc++.h>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        ListNode *fast = head;
        ListNode *low = head;
        while (fast) {
            if (fast->next) {
                fast = fast->next->next;
            } else {
                return false;
            }
            low = low->next;
            if (fast == low) {
                return true;
            }
        }
        return false;
    }
};
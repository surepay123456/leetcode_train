#include <bits/stdc++.h>

#include <array>
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        return add(l1, l2, 0);
    }

   private:
    ListNode* add(ListNode* l1, ListNode* l2, int carry) {
        if (!l1 && !l2) {
            if (carry == 0) {
                return nullptr;
            } else {
                return new ListNode(carry);
            }
        }
        if (!l1) {
            swap(l1, l2);
        }

        carry += l1->val + (l2 ? l2->val : 0);
        l1->val = carry % 10;
        l1->next = add(l1->next, l2 ? l2->next : nullptr, carry / 10);
        return l1;
    }
};
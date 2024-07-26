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
    ListNode* sortList(ListNode* head) {
        // 归并排序
        // 单个元素情况
        if (!head || !head->next) {
            return head;
        }
        ListNode* dummpyNode = new ListNode();
        dummpyNode->next = head;
        ListNode *low = dummpyNode, *fast = dummpyNode;
        while (fast && fast->next) {
            low = low->next;
            fast = fast->next->next;
        }
        ListNode* nxt = low->next;
        low->next = nullptr;
        ListNode* leftList = sortList(head);
        ListNode* rightList = sortList(nxt);
        // 合并
        ListNode* cur = dummpyNode;
        while (leftList && rightList) {
            if (leftList->val > rightList->val) {
                cur->next = rightList;
                rightList = rightList->next;
                cur = cur->next;
            } else {
                cur->next = leftList;
                leftList = leftList->next;
                cur = cur->next;
            }
        }
        if (leftList) {
            cur->next = leftList;
        }
        if (rightList) {
            cur->next = rightList;
        }
        cur = dummpyNode->next;
        delete dummpyNode;
        return cur;
    }
};
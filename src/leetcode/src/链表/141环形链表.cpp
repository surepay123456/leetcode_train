#include "header.h"

class Solution {
   public:
    bool hasCycle(ListNode *head) {
        // 链表的快慢指针
        // 快指针一次移动两个单元 如果遇到nullptr 则证明不存在环
        if (!head) return false;
        ListNode *fast = head;
        ListNode *low = head;
        // 每次循环中 移动两个指针 如果两个指针指向同一个值则证明存在环
        // 此处初始是一样的 也可以加个dummpy节点
        while (1) {
            low = low->next;
            if (fast->next)
                fast = fast->next->next;
            else
                return false;
            if (!fast) return false;
            if (low == fast) return true;
        }
    }
};
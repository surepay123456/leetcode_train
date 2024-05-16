#include <deque>

#include "header.h"

class Solution {
   public:
    bool isPalindrome(ListNode* head) {
        //由于链表只能顺序遍历
        //用一个双端队列来存储
        deque<int> que;
        while (head) {
            que.push_back(head->val);
            head = head->next;
        }
        if(que.size() == 1) return true; 
        while(!que.empty()){
            int left = que.back();
            int right = que.front();
            if(left != right) return false;
            que.pop_front();
            que.pop_back();
            if(que.size() == 1) return true;
        }
        return  true;
    }
};
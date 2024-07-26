#include <bits/stdc++.h>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
   public:
    bool isPalindrome(ListNode *head) {
        vector<int> vec;
        while (head) {
            vec.push_back(head->val);
            head  =head->next;
        }
        int  n  = vec.size();
        int l = 0;
        int r = n  -1;
        while (l <= r) {
            if (vec[l] != vec[r]) {
                return false;
            }
            l ++;
            r --;
        }
        return true;
    }
};
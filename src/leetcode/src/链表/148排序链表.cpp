#include <bits/stdc++.h>

#include <algorithm>
#include <vector>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;
class Solution {
   public:
    ListNode* sortList(ListNode* head) {
        // 暴力解法 vector存储 再排序 再得到结果 消耗的额外空间为n
        vector<int> vec;
        ListNode* node = head;
        while (node) {
            vec.push_back(node->val);
            node = node->next;
        }

        sort(vec.begin(), vec.end());
        int n = vec.size();
        ListNode* result = head;
        for (int i = 0; i < n; i++) {
            head->val = vec[i];
            head = head->next;
        }
        return result;

        // 归并排序
        

    }
};
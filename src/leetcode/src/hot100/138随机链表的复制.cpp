#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;

    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
   public:
    Node* copyRandomList(Node* head) {
        //随机链表的深拷贝
        unordered_map<Node*, Node*> hashMap;
        Node* cur = head;
        while (cur) {
            Node* temp = new Node(cur->val);
            hashMap[cur] = temp;
            cur = cur->next;
        }  
        cur = head;
        while (cur) {
            hashMap[cur]->next = hashMap[cur->next];
            hashMap[cur]->random = hashMap[cur->random];
            cur = cur->next;
        }
        return hashMap[head];
    }
};
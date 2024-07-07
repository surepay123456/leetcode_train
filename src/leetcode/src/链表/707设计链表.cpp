#include <bits/stdc++.h>

#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class MyLinkedList {
   private:
    ListNode* dummpyNode;
    int size_;

   public:
    MyLinkedList() {
        dummpyNode = new ListNode(0);
        size_ = 0;
    }

    int get(int index) {
        if (index >= size_) {
            return -1;
        }
        ListNode* cur = dummpyNode;
        // index == 0的情况返回dummpyNode -> next
        index++;
        int val;
        while (index-- && cur != nullptr) {
            cur = cur->next;
            val = cur->val;
        }
        return val;
    }

    void addAtHead(int val) {
        ListNode* newNode = new ListNode(val);
        newNode->next = dummpyNode->next;
        dummpyNode->next = newNode;
        size_++;
    }

    void addAtTail(int val) {
        ListNode* cur = dummpyNode;
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        ListNode* newNode = new ListNode(val);
        cur->next = newNode;
        size_++;
    }

    void addAtIndex(int index, int val) {
        //注意index可以等于0
        //找到插入位置的前一个节点
        if (index > size_) {
            return;
        }
        ListNode* cur = dummpyNode;
        while (index--) {
            cur = cur->next;
        }
        ListNode* newNode = new ListNode(val);
        newNode->next = cur->next;
        cur->next = newNode;
        size_++;
    }

    void deleteAtIndex(int index) {
        if (index >= size_) {
            return;
        }
        ListNode* cur = dummpyNode;
        // 找到删除节点的前一个节点
        // 注意index == 0的情况
        while (index--) {
            cur = cur->next;
        }
        ListNode* toDel = cur->next;
        cur->next = cur->next->next;
        delete toDel;
        size_--;
    }

    void print() {
        ListNode* cur = dummpyNode;
        while (cur->next != nullptr) {
            cout << cur->next->val << " ";
            cur = cur->next;
        }
        cout << endl;
    }
};

int main() {
    MyLinkedList mylist;
    // mylist.addAtHead(1);
    // mylist.addAtTail(3);
    // mylist.print();
    // mylist.addAtIndex(1, 2);
    // mylist.print();
    // cout << mylist.get(1) << endl;
    // mylist.deleteAtIndex(1);
    // mylist.print();
    // cout << mylist.get(2) << endl;

    mylist.addAtHead(7);
    mylist.addAtHead(2);
    mylist.addAtHead(1);
    mylist.print();
    mylist.addAtIndex(3, 0);
    mylist.deleteAtIndex(2);
    mylist.print();
    mylist.addAtHead(6);
    mylist.addAtTail(4);
    mylist.print();
    cout << mylist.get(4) << endl;;
    return 0;
}

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */
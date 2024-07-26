#include <bits/stdc++.h>
#include <dbg.h>

#include <iostream>
#include <list>
#include <ostream>
#include <ratio>
#include <unordered_map>
#include <unordered_set>
using namespace std;

struct doubleListNode {
    int val;
    int key;
    doubleListNode* prev;
    doubleListNode* next;
    doubleListNode(int val) : val(val), prev(nullptr), next(nullptr) {}
    doubleListNode() : val(0), prev(nullptr), next(nullptr) {}
};

class LRUCache {
   public:
    LRUCache(int capacity) : capacity_(capacity) {
        dummpyNode = new doubleListNode(0);
        dummpyNode->next = dummpyNode;
        dummpyNode->prev = dummpyNode;
        curCapacity = 0;
    }

    int get(int key) {
        // key映射 指针
        if (!hashTable.count(key)) {
            return -1;
        }
        doubleListNode* cur = hashTable[key];
        forward(cur);
        return cur->val;
    }
    void forward(doubleListNode* cur) {
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
        //移到首位
        cur->next = dummpyNode->next;
        dummpyNode->next->prev = cur;
        dummpyNode->next = cur;
        cur->prev = dummpyNode;
    }
    void put(int key, int value) {
        //先看看是否存在
        if (hashTable.count(key)) {
            //存在
            //将其脱离 再移到dummpyNode后
            doubleListNode* cur = hashTable[key];
            forward(cur);
            cur->val = value;
            return;
        }
        //如果不存在 则判断是否大于容量
        if (curCapacity == capacity_) {
            doubleListNode* toDel = dummpyNode->prev;
            dummpyNode->prev = toDel->prev;
            toDel->prev->next = dummpyNode;
            //删除这个节点 哈希表删除
            //不知道key是什么
            hashTable.erase(hashTable.find(toDel->key));
            delete toDel;
            curCapacity--;
        }

        //移到首位
        doubleListNode* cur = new doubleListNode(value);
        cur->next = dummpyNode->next;
        dummpyNode->next->prev = cur;
        dummpyNode->next = cur;
        cur->prev = dummpyNode;
        //参数赋值
        cur->val = value;
        cur->key = key;
        // hash表建立映射
        hashTable[key] = cur;
        curCapacity++;
        // dbg(key, value, hashTable, curCapacity);
        return;
    }

   private:
    int capacity_;
    int curCapacity;
    doubleListNode* dummpyNode;
    unordered_map<int, doubleListNode*> hashTable;
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */

int main() {
    LRUCache lru(2);
    lru.put(1, 1);
    lru.put(2, 2);
    cout << lru.get(1) << endl;
    lru.put(3, 3);
    cout << lru.get(2) << endl;
    lru.put(4, 4);
    cout << lru.get(1) << endl;
    cout << lru.get(3) << endl;
    cout << lru.get(4) << endl;
    return 0;
}
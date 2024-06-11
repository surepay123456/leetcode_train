#include <bits/stdc++.h>

#include <ostream>
using namespace std;
struct node {
    bool isEnd = false;
    node* next[26] = {nullptr};
    node() : isEnd(false) {
        memset(next, 0, sizeof(next));
    }
};
class Trie {
   private:
    node* top;

   public:
    Trie() { top = new node(); }

    void insert(string word) {
        node* currentNode = new node();
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->next[index] == nullptr) {
                currentNode->next[index] = new node();
            }
            currentNode = currentNode->next[index];
        }
        currentNode->isEnd = true;
    }

    bool search(string word) {
        node* currentNode = new node();
        for (char ch : word) {
            int index = ch - 'a';
            if (currentNode->next[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->next[index];
        }
        if (currentNode->isEnd) {
            return true;
        } else {
            return false;
        }
    }

    bool startsWith(string prefix) {
        node* currentNode = new node();
        for (char ch : prefix) {
            int index = ch - 'a';
            if (currentNode->next[index] == nullptr) {
                return false;
            }
            currentNode = currentNode->next[index];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
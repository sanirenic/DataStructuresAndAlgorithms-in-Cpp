/*Problem Statement: 
“Design a data structure that follows the constraints of Least Recently Used (LRU) cache”.*/

#include <bits/stdc++.h>
using namespace std;

class LRUCache {
public:
    class node {
    public:
        int key;
        int val;
        node* next;
        node* prev;
        node(int _key, int _val) {
            key = _key;
            val = _val;
        }
    };

    node* head = new node(-1, -1);
    node* tail = new node(-1, -1);

    int cap;
    unordered_map<int, node*> m;

    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }

    void addnode(node* newnode) {
        node* temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node* delnode) {
        node* delprev = delnode->prev;
        node* delnext = delnode->next;
        delprev->next = delnext;
        delnext->prev = delprev;
    }

    int get(int key_) {
        if (m.find(key_) != m.end()) {
            node* resnode = m[key_];
            int res = resnode->val;
            m.erase(key_);
            deletenode(resnode);
            addnode(resnode);
            m[key_] = head->next;
            return res;
        }
        return -1;
    }

    void put(int key_, int value) {
        if (m.find(key_) != m.end()) {
            node* existingnode = m[key_];
            m.erase(key_);
            deletenode(existingnode);
        }
        if (m.size() == cap) {
            m.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        node* newNode = new node(key_, value);
        addnode(newNode);
        m[key_] = newNode;
    }
};

// Driver Code
int main() {
    LRUCache cache(2); // Capacity of 2

    cache.put(1, 10);
    cache.put(2, 20);
    cout << cache.get(1) << endl; // Returns 10
    cache.put(3, 30); // Removes key 2 (Least Recently Used)
    cout << cache.get(2) << endl; // Returns -1 (Not Found)
    cache.put(4, 40); // Removes key 1
    cout << cache.get(1) << endl; // Returns -1
    cout << cache.get(3) << endl; // Returns 30
    cout << cache.get(4) << endl; // Returns 40

    return 0;
}

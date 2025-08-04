#include <iostream>
#include <unordered_map>
using namespace std;

class LRUCache {
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k, int v): key(k), value(v), prev(NULL), next(NULL) {}
    };

    int cap;
    unordered_map<int, Node*> cache;
    Node* head;  // dummy head
    Node* tail;  // dummy tail

    void removeNode(Node* node) {
        Node* before = node->prev;
        Node* after = node->next;
        before->next = after;
        after->prev = before;
    }

    void insertAtFront(Node* node) {
        Node* after = head->next;
        head->next = node;
        node->prev = head;
        node->next = after;
        after->prev = node;
    }

public:
    LRUCache(int capacity) {
        cap = capacity;
        head = new Node(0, 0);  // dummy head
        tail = new Node(0, 0);  // dummy tail
        head->next = tail;
        tail->prev = head;
    }

    int get(int key) {
        if (cache.find(key) == cache.end())
            return -1;

        Node* node = cache[key];
        removeNode(node);
        insertAtFront(node);
        return node->value;
    }

    void put(int key, int value) {
        if (cache.find(key) != cache.end()) {
            Node* existing = cache[key];
            existing->value = value;
            removeNode(existing);
            insertAtFront(existing);
        } else {
            if (cache.size() == cap) {
                Node* lru = tail->prev;
                removeNode(lru);
                cache.erase(lru->key);
                delete lru;
            }
            Node* newNode = new Node(key, value);
            insertAtFront(newNode);
            cache[key] = newNode;
        }
    }
};

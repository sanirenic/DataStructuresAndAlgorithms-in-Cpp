#include <iostream>
using namespace std;

// Doubly Linked List Node
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// Function to append new node at the end
void append(Node*& head, Node*& tail, int val) {
    Node* newNode = new Node(val);
    if (!head) {
        head = tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

// Function to remove duplicates from sorted DLL
Node* removeDuplicates(Node* head) {
    Node* curr = head;

    while (curr && curr->next) {
        if (curr->data == curr->next->data) {
            // Duplicate found – remove next node
            Node* dup = curr->next;
            curr->next = dup->next;
            if (dup->next) {
                dup->next->prev = curr;
            }
            delete dup; // Free memory
        } else {
            curr = curr->next; // Move forward only if no deletion
        }
    }

    return head;
}

// Function to print the DLL
void printList(Node* head) {
    while (head) {
        cout << head->data;
        if (head->next) cout << " <-> ";
        head = head->next;
    }
    cout << endl;
}

// Main
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, val;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter sorted node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        append(head, tail, val);
    }

    head = removeDuplicates(head);

    cout << "List after removing duplicates: ";
    printList(head);

    return 0;
}

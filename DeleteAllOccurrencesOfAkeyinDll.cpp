#include <iostream>
using namespace std;

// Definition of a Node in DLL
struct Node {
    int data;
    Node* prev;
    Node* next;

    Node(int val) {
        data = val;
        prev = next = nullptr;
    }
};

// Function to append node at the end of the DLL
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

// Function to delete all nodes with target value
Node* deleteTarget(Node* head, int target) {
    Node* curr = head;

    while (curr) {
        Node* nextNode = curr->next;

        if (curr->data == target) {
            // Adjust previous node's next
            if (curr->prev) {
                curr->prev->next = curr->next;
            } else {
                // curr is the head
                head = curr->next;
            }

            // Adjust next node's prev
            if (curr->next) {
                curr->next->prev = curr->prev;
            }

            delete curr; // Free memory
        }

        curr = nextNode;
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

// Main function
int main() {
    Node* head = nullptr;
    Node* tail = nullptr;
    int n, val, target;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter node values: ";
    for (int i = 0; i < n; ++i) {
        cin >> val;
        append(head, tail, val);
    }

    cout << "Enter target value to delete: ";
    cin >> target;

    head = deleteTarget(head, target);

    cout << "Modified DLL: ";
    printList(head);

    return 0;
}

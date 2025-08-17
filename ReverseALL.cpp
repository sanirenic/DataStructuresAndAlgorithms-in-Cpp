#include <bits/stdc++.h>
using namespace std;


class Node{
    public:

    int data;
    Node* next;
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
    }
};

Node* reverseLL(Node* head){
    if(head==NULL || head->next=NULL){
        return head;
    }
    Node* newHead=reverseLL(head->next);
    Node* front=head->next;
    front->next=head;
    head->next=NULL;
    return newHead;
}

void printLL(Node* head){
    Node* temp=head;
    while(temp!=nullptr){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int main() {
    // Create a linked list with
    // values 1, 3, 2, and 4
    Node* head = new Node(1);
    head->next = new Node(3);
    head->next->next = new Node(2);
    head->next->next->next = new Node(4);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    // Reverse the linked list
    head = reverseLL(head);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printLL(head);

    return 0;
}
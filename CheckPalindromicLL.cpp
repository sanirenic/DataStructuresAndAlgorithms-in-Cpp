
#include <iostream>
#include <bits/stdc++.h>

using namespace std;

class Node {
public:

    int data;   
    Node* next;      

    Node(int data1, Node* next1) {
        data = data1;
        next = next1;
    }

    Node(int data1) {
        data = data1;
        next = nullptr;
    }
};


Node* reverseLL(Node* head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    Node* newHead=reverseLL(head->next);
    Node* front=head->next;
    head->next=NULL;

    return newHead;
}
bool isPalindrome(Node* head){
    if(head==NULL ||head->next==NULL){
        return head;
    }
    Node* slow=head;
    Node* fast=head;

    while(fast->next!=NULL && fast->next->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
    }
    Node* newHead=reverseLL(slow->next);
    Node* first=head;
    Node* second=newHead;

    while(second!=NULL){
        if(first->data!=second->data){
            reverseLL(newHead);
            return false;
        }
        first=first->next;
        second=second->next;
    }
    reverseLL(newHead);
    return true;
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

    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLL(head);

    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}

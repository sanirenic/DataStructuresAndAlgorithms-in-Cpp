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

Node* sortTwoLL(Node*list1, NOde*list2){
    Node* dummyNode=new Node(-1);
    Node* temp=dummyNode;

    while(list1!=nullptr && list2!=nullptr){
        if(lis1->data<=list2->data){
            temp->next=list1;
            list1=list1->next;
        }
        else{
            temp->next=list2;
            list2=list2->next;
        }
        temp=temp->next;
    }
    if(list1!=nullptr){
        temp->next=list1;
    }
    else{
        temp->next=list2;
    }
    return dummyNode->next;
}

void printLL(Node* head){
    Node* temp=head;
    while (temp!=nullptr)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}


int main() {
    // Example Linked Lists
    Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

    cout << "First sorted linked list: ";
    printLL(list1);

    cout << "Second sorted linked list: ";
    printLL(list2);

    Node* mergedList = sortTwoLL(list1, list2);

    cout << "Merged sorted linked list: ";
    printLL(mergedList);

    return 0;
}
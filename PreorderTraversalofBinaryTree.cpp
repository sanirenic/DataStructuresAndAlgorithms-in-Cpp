/*Problem Statement: Given the root of a Binary Tree, 
write a recursive function that returns an array containing the preorder traversal of the tree.*/

                            
#include <iostream>
#include <vector>

using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};


void preorder(Node* root, vector<int> &arr){
    
    if(root == nullptr){
        return;
    }
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

vector<int> preOrder(Node* root){
    vector<int> arr;
    preorder(root, arr);
    return arr;
}

int main()
{
    Node* root = new Node(3);
    root->left = new Node(4);
    root->right = new Node(8);
    root->left->left = new Node(10);
    root->left->right = new Node(12);

    vector<int> result = preOrder(root);

    
    cout << "Preorder Traversal: ";
    
    for(int val : result) {
        cout << val << " ";
    }
    cout << endl;


    return 0;
}

                            
                        
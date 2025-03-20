/*You are given an array nodes. It contains 7 integers, 
which represents the value of nodes of the binary tree in level order traversal.
 You are also given a root of the tree which has a value equal to nodes[0].

Your task to construct a binary tree by creating nodes for the remaining 6 nodes.*/

#include <iostream>
#include <vector>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};


void create_tree(Node* root, vector<int>& vec) {
    vector<Node*> nodes(7);
    nodes[0] = root;

    for (int i = 1; i < 7; i++) {
        nodes[i] = new Node(vec[i]);
    }

    for (int i = 0; i < 7; i++) {
        int leftIndex = 2 * i + 1;
        int rightIndex = 2 * i + 2;

        if (leftIndex < 7) nodes[i]->left = nodes[leftIndex];
        if (rightIndex < 7) nodes[i]->right = nodes[rightIndex];
    }
}

// Inorder Traversal to check the tree
void inorder(Node* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

int main() {
    vector<int> vec = {1, 2, 3, 4, 5, 6, 7};
    Node* root = new Node(vec[0]);
    create_tree(root, vec);
    cout << "Inorder Traversal: ";
    inorder(root);
    return 0;
}

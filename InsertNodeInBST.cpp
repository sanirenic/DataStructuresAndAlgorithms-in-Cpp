#include <iostream>
using namespace std;

// Node structure for BST
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(NULL), right(NULL) {}
};

// Recursive function to insert a value into BST
Node* insert(Node* root, int val) {
    if (root == NULL) {
        return new Node(val); // Insert at correct position
    }

    if (val < root->data) {
        root->left = insert(root->left, val); // Go left
    } else {
        root->right = insert(root->right, val); // Go right
    }

    return root;
}

// Inorder traversal (left, root, right)
void inorder(Node* root) {
    if (root == NULL) return;
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

// Search for a value to confirm insertion
bool search(Node* root, int val) {
    if (!root) return false;
    if (root->data == val) return true;
    if (val < root->data) return search(root->left, val);
    return search(root->right, val);
}

int main() {
    // Initial tree: [4, 2, 7, 1, 3]
    Node* root = new Node(4);
    root->left = new Node(2);
    root->right = new Node(7);
    root->left->left = new Node(1);
    root->left->right = new Node(3);

    int val = 5;

    // Insert value into BST
    root = insert(root, val);

    // Print inorder traversal
    cout << "Inorder traversal: ";
    inorder(root);
    cout << endl;

    // Verify insertion
    cout << "Value " << val << " inserted: " << (search(root, val) ? "true" : "false") << endl;

    return 0;
}

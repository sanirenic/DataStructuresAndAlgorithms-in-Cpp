#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

int findFloor(Node* root, int key) {
    if (!root) return -1;
    if (root->data == key) return root->data;
    if (root->data > key) return findFloor(root->left, key);

    int floorVal = findFloor(root->right, key);
    return (floorVal <= key && floorVal != -1) ? floorVal : root->data;
}

int findCeil(Node* root, int key) {
    if (!root) return -1;
    if (root->data == key) return root->data;
    if (root->data < key) return findCeil(root->right, key);

    int ceilVal = findCeil(root->left, key);
    return (ceilVal >= key && ceilVal != -1) ? ceilVal : root->data;
}

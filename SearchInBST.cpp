#include <iostream>
using namespace std;

// Definition of Tree Node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) {
        val = x;
        left = right = nullptr;
    }
};

// BST Insert Function
TreeNode* insert(TreeNode* root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (val < root->val)
        root->left = insert(root->left, val);
    else
        root->right = insert(root->right, val);
    return root;
}

// Recursive Search Function
TreeNode* searchBST(TreeNode* root, int val) {
    if (root == nullptr || root->val == val) return root;
    if (val < root->val)
        return searchBST(root->left, val);
    else
        return searchBST(root->right, val);
}

// Pre-order Traversal to Print Subtree
void preorder(TreeNode* root) {
    if (root == nullptr) return;
    cout << root->val << " ";
    preorder(root->left);
    preorder(root->right);
}

// Main Function
int main() {
    TreeNode* root = nullptr;
    int values[] = {4, 2, 7, 1, 3};
    for (int val : values)
        root = insert(root, val);

    int searchVal = 2;
    TreeNode* result = searchBST(root, searchVal);

    if (result) {
        cout << "Subtree rooted at node " << searchVal << ": ";
        preorder(result);
    } else {
        cout << "Value " << searchVal << " not found in BST.";
    }
    cout << endl;
    return 0;
}

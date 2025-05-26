#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Helper function to check mirror
bool isMirror(TreeNode* left, TreeNode* right) {
    if (!left && !right) return true;  // both null
    if (!left || !right) return false; // only one null
    return (left->val == right->val)
        && isMirror(left->left, right->right)
        && isMirror(left->right, right->left);
}

// Main function
bool isSymmetric(TreeNode* root) {
    if (!root) return true;
    return isMirror(root->left, root->right);
}

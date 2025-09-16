#include <iostream>
#include <climits>
using namespace std;

// Definition of a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Helper function to validate BST with range constraints
    bool helper(TreeNode* root, long long minVal, long long maxVal) {
        if (!root) return true;  // empty tree is valid
        if (root->val <= minVal || root->val >= maxVal) return false;
        return helper(root->left, minVal, root->val) &&
               helper(root->right, root->val, maxVal);
    }

    // Main function to check if tree is a valid BST
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }
};

// Utility function to create a new node
TreeNode* newNode(int val) {
    return new TreeNode(val);
}

int main() {
    Solution sol;

    // Example 1: Valid BST
    TreeNode* root1 = newNode(2);
    root1->left = newNode(1);
    root1->right = newNode(3);

    cout << "Tree 1 is a valid BST? " 
         << (sol.isValidBST(root1) ? "Yes" : "No") << endl;

    // Example 2: Invalid BST
    TreeNode* root2 = newNode(5);
    root2->left = newNode(1);
    root2->right = newNode(4);
    root2->right->left = newNode(3);
    root2->right->right = newNode(6);

    cout << "Tree 2 is a valid BST? " 
         << (sol.isValidBST(root2) ? "Yes" : "No") << endl;

    return 0;
}

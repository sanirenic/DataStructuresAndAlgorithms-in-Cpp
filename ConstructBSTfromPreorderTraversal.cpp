#include <iostream>
#include <vector>
#include <climits>
using namespace std;

// TreeNode structure
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Solution class to build BST from preorder
class Solution {
public:
    int idx = 0;

    TreeNode* buildBST(vector<int>& preorder, long long minVal, long long maxVal) {
        // Base case: if all nodes are processed
        if (idx >= preorder.size()) return NULL;

        int val = preorder[idx];

        // If current value doesn’t fit in range, return NULL
        if (val < minVal || val > maxVal) return NULL;

        // Create root node
        TreeNode* root = new TreeNode(val);
        idx++;

        // Recursively build left and right subtrees
        root->left = buildBST(preorder, minVal, val - 1LL);
        root->right = buildBST(preorder, val + 1LL, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, LLONG_MIN, LLONG_MAX);
    }
};

// Utility function: inorder traversal to check correctness
void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

// Utility function: preorder traversal to confirm reconstruction
void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal (should be sorted): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal (should match input): ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

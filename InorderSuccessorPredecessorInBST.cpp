#include <iostream>
using namespace std;

// Node definition
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// BST utility functions
TreeNode* insert(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insert(root->left, val);
    else root->right = insert(root->right, val);
    return root;
}

class Solution {
public:
    // find maximum in subtree
    TreeNode* findMax(TreeNode* node) {
        while (node && node->right) node = node->right;
        return node;
    }

    // find minimum in subtree
    TreeNode* findMin(TreeNode* node) {
        while (node && node->left) node = node->left;
        return node;
    }

    // function to find predecessor and successor
    pair<int,int> findPreSuc(TreeNode* root, int key) {
        TreeNode* pre = NULL;
        TreeNode* suc = NULL;
        TreeNode* curr = root;

        while (curr) {
            if (curr->val == key) {
                // predecessor = max in left subtree
                if (curr->left) pre = findMax(curr->left);
                // successor = min in right subtree
                if (curr->right) suc = findMin(curr->right);
                break;
            } 
            else if (key < curr->val) {
                suc = curr;  // possible successor
                curr = curr->left;
            } 
            else {
                pre = curr;  // possible predecessor
                curr = curr->right;
            }
        }

        return {pre ? pre->val : -1, suc ? suc->val : -1};
    }
};

// inorder traversal for checking BST structure
void inorder(TreeNode* root) {
    if (!root) return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = NULL;
    int keys[] = {50, 30, 20, 40, 70, 60, 80};

    // build BST
    for (int val : keys) {
        root = insert(root, val);
    }

    cout << "Inorder traversal of BST: ";
    inorder(root);
    cout << endl;

    Solution sol;
    int key = 65;
    auto ans = sol.findPreSuc(root, key);

    cout << "Key: " << key << endl;
    cout << "Predecessor: " << ans.first << endl;
    cout << "Successor: " << ans.second << endl;

    return 0;
}

#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isMirror(TreeNode* t1, TreeNode* t2) {
        if (!t1 && !t2) return true;      // both null → symmetric
        if (!t1 || !t2) return false;     // one null → not symmetric
        return (t1->val == t2->val) &&
               isMirror(t1->left, t2->right) &&
               isMirror(t1->right, t2->left);
    }

    bool isSymmetric(TreeNode* root) {
        if (!root) return true; // empty tree is symmetric
        return isMirror(root->left, root->right);
    }
};


// Helper function to create a sample tree
TreeNode* buildSampleTree() {
    /*
           1
         /   \
        2     2
       / \   / \
      3   4 4   3
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(4);
    root->right->left = new TreeNode(4);
    root->right->right = new TreeNode(3);
    return root;
}

int main() {
    Solution sol;

    TreeNode* root = buildSampleTree();
    if (sol.isSymmetric(root))
        cout << "The tree is symmetric ✅" << endl;
    else
        cout << "The tree is NOT symmetric ❌" << endl;

    return 0;
}

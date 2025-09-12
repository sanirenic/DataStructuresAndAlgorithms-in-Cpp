#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// Recursive BST search (uses BST property)
TreeNode* searchBST(TreeNode* root, int val) {
    if (!root || root->val == val) return root;
    if (val < root->val) return searchBST(root->left, val);
    return searchBST(root->right, val);
}

// Insert into BST
TreeNode* insertBST(TreeNode* root, int val) {
    if (!root) return new TreeNode(val);
    if (val < root->val) root->left = insertBST(root->left, val);
    else root->right = insertBST(root->right, val);
    return root;
}

// Print level order
void printLevelOrder(TreeNode* root) {
    if (!root) { cout << "null" << endl; return; }
    queue<TreeNode*> q; q.push(root);
    while (!q.empty()) {
        TreeNode* node = q.front(); q.pop();
        if (node) {
            cout << node->val << " ";
            q.push(node->left);
            q.push(node->right);
        } else cout << "null ";
    }
    cout << endl;
}

int main() {
    TreeNode* root = NULL;
    root = insertBST(root, 4);
    insertBST(root, 2);
    insertBST(root, 7);
    insertBST(root, 1);
    insertBST(root, 3);

    int val = 2;
    TreeNode* ans = searchBST(root, val);
    printLevelOrder(ans);
}

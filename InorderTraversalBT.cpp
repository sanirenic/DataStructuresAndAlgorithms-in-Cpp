#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void inorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    inorderHelper(root->left, result);   // Left
    result.push_back(root->val);        // Root
    inorderHelper(root->right, result); // Right
}

vector<int> inorderTraversal(TreeNode* root) {
    vector<int> result;
    inorderHelper(root, result);
    return result;
}

int main() {
    // Example: [1,null,2,3]
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> ans = inorderTraversal(root);
    for (int x : ans) cout << x << " ";
}

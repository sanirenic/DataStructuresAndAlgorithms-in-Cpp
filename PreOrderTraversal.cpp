#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void preorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;
    result.push_back(root->val);           // Visit root
    preorderHelper(root->left, result);    // Left
    preorderHelper(root->right, result);   // Right
}

vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    preorderHelper(root, result);
    return result;
}

int main() {
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = preorderTraversal(root);
    for (int x : res) cout << x << " ";
}

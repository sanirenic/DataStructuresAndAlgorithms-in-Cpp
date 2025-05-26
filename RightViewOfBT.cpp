#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<int> rightView(TreeNode* root) {
    vector<int> view;
    if (!root) return view;

    queue<TreeNode*> q;
    q.push(root);

    while (!q.empty()) {
        int n = q.size();  // number of nodes at current level
        for (int i = 0; i < n; ++i) {
            TreeNode* curr = q.front();
            q.pop();

            // if it's the last node in this level, add to view
            if (i == n - 1) view.push_back(curr->val);

            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }
    }
    return view;
}

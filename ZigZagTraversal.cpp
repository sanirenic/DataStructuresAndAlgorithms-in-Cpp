/*Zig Zag or Spiral Traversal

Given the root of a binary tree, return the zigzag level order traversal of its nodes' values.
(i.e., from left to right, then right to left for the next level and alternate between).

Examples:
Input : root = [1, 2, 3, null, 4, 8, 5]
Output : [ [1] , [3, 2], [4, 8, 5] ]

Explanation : So at root we move from left to right.
At next level we move in opposite direction i.e. from right to left.
At next level again reverse the traversal i.e. from left to right.*/

#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(NULL), right(NULL) {}
};

vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
    vector<vector<int>> result;
    if (!root) return result;

    queue<TreeNode*> q;
    q.push(root);
    bool leftToRight = true;

    while (!q.empty()) {
        int size = q.size();
        vector<int> level;

        for (int i = 0; i < size; ++i) {
            TreeNode* node = q.front(); q.pop();
            level.push_back(node->val);

            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
        }

        if (!leftToRight)
            reverse(level.begin(), level.end());

        result.push_back(level);
        leftToRight = !leftToRight;
    }

    return result;
}

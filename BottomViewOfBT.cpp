#include <iostream>
#include <queue>
#include <map>
#include <vector>
using namespace std;

// Definition for a binary tree node
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

// Function to compute bottom view
vector<int> bottomView(TreeNode* root) {
    if (!root) return {};

    // Map to store the last node at each horizontal distance (HD)
    map<int, int> hdNodeMap;  // HD -> node value

    // Queue for BFS: each element is a pair of node and its HD
    queue<pair<TreeNode*, int>> q;
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // Update the map (bottom view gets the last node at that HD)
        hdNodeMap[hd] = node->val;

        // Add left child with HD - 1
        if (node->left) {
            q.push({node->left, hd - 1});
        }

        // Add right child with HD + 1
        if (node->right) {
            q.push({node->right, hd + 1});
        }
    }

    // Extract values from the map
    vector<int> result;
    for (auto& [hd, val] : hdNodeMap) {
        result.push_back(val);
    }

    return result;
}

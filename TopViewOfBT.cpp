#include <iostream>
#include <queue>
#include <map>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<int> topView(TreeNode* root) {
    if (!root) return {};

    map<int, int> topNode; // HD -> node value
    queue<pair<TreeNode*, int>> q; // Node + horizontal distance
    q.push({root, 0});

    while (!q.empty()) {
        auto [node, hd] = q.front();
        q.pop();

        // If no node is present at this HD, set it
        if (topNode.find(hd) == topNode.end()) {
            topNode[hd] = node->val;
        }

        if (node->left)
            q.push({node->left, hd - 1});
        if (node->right)
            q.push({node->right, hd + 1});
    }

    vector<int> result;
    for (auto& [hd, val] : topNode) {
        result.push_back(val);
    }
    return result;
}

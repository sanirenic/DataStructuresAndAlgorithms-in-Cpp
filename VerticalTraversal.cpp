#include <iostream>
#include <vector>
#include <tuple>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

vector<vector<int>> verticalTraversal(TreeNode* root) {
    map<int, vector<pair<int, int>>> nodesByColumn; 
    queue<tuple<TreeNode*, int, int>> q; 

    q.emplace(root, 0, 0);

    while (!q.empty()) {
        auto [node, row, col] = q.front(); q.pop();
        nodesByColumn[col].emplace_back(row, node->val);

        if (node->left) {
            q.emplace(node->left, row + 1, col - 1);
        }
        if (node->right) {
            q.emplace(node->right, row + 1, col + 1);
        }
    }

    vector<vector<int>> result;
    for (auto& [col, vec] : nodesByColumn) {
        sort(vec.begin(), vec.end()); 
        vector<int> colVals;
        for (auto& [row, val] : vec) {
            colVals.push_back(val);
        }
        result.push_back(colVals);
    }
    return result;
}

TreeNode* buildExampleTree() {

    TreeNode* root = new TreeNode(3);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    TreeNode* root = buildExampleTree();
    vector<vector<int>> output = verticalTraversal(root);

    cout << "Vertical Order Traversal:\n";
    for (const auto& column : output) {
        cout << "[ ";
        for (int val : column)
            cout << val << " ";
        cout << "]\n";
    }

    return 0;
}

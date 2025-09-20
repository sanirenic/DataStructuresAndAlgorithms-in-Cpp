#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isLeaf(TreeNode* node) {
        return (!node->left && !node->right);
    }

    void addLeftBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->left;
        while (curr) {
            if (!isLeaf(curr)) res.push_back(curr->val);
            if (curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }

    void addLeaves(TreeNode* root, vector<int>& res) {
        if (!root) return;
        if (isLeaf(root)) {
            res.push_back(root->val);
            return;
        }
        addLeaves(root->left, res);
        addLeaves(root->right, res);
    }

    void addRightBoundary(TreeNode* root, vector<int>& res) {
        TreeNode* curr = root->right;
        vector<int> temp;
        while (curr) {
            if (!isLeaf(curr)) temp.push_back(curr->val);
            if (curr->right) curr = curr->right;
            else curr = curr->left;
        }
        // Add in reverse order
        for (int i = temp.size()-1; i >= 0; i--) {
            res.push_back(temp[i]);
        }
    }

    vector<int> boundaryTraversal(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        if (!isLeaf(root)) res.push_back(root->val); // root is part of boundary
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

// ----------- MAIN FUNCTION TO TEST -----------
int main() {
    /*
            1
           / \
          2   3
         / \   \
        4   5   6
           / \  /
          7  8 9
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right->right = new TreeNode(6);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(8);
    root->right->right->left = new TreeNode(9);

    Solution sol;
    vector<int> boundary = sol.boundaryTraversal(root);

    cout << "Boundary Traversal: ";
    for (int val : boundary) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

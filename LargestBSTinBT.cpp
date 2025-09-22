#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
    struct NodeInfo {
        bool isBST;
        int size;
        int minVal;
        int maxVal;
    };

    NodeInfo solve(TreeNode* root, int &maxSize) {
        if (!root) return {true, 0, INT_MAX, INT_MIN};

        NodeInfo left = solve(root->left, maxSize);
        NodeInfo right = solve(root->right, maxSize);

        NodeInfo curr;

        if (left.isBST && right.isBST && root->val > left.maxVal && root->val < right.minVal) {
            curr.isBST = true;
            curr.size = left.size + right.size + 1;
            curr.minVal = min(root->val, left.minVal);
            curr.maxVal = max(root->val, right.maxVal);
            maxSize = max(maxSize, curr.size);
        } else {
            curr.isBST = false;
            curr.size = 0;
            curr.minVal = INT_MIN;
            curr.maxVal = INT_MAX;
        }

        return curr;
    }

public:
    int largestBST(TreeNode* root) {
        int maxSize = 0;
        solve(root, maxSize);
        return maxSize;
    }
};

TreeNode* buildSampleTree() {
    
    TreeNode* root = new TreeNode(10);
    root->left = new TreeNode(5);
    root->right = new TreeNode(15);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(8);
    root->right->right = new TreeNode(7);
    return root;
}

int main() {
    Solution sol;
    TreeNode* root = buildSampleTree();
    cout << "Size of the largest BST is: " << sol.largestBST(root) << endl;
    return 0;
}

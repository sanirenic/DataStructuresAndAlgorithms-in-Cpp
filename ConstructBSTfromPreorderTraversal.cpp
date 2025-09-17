#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int idx = 0;

    TreeNode* buildBST(vector<int>& preorder, long long minVal, long long maxVal) {
       
        if (idx >= preorder.size()) return NULL;

        int val = preorder[idx];
        if (val < minVal || val > maxVal) return NULL;

        TreeNode* root = new TreeNode(val);
        idx++;

        root->left = buildBST(preorder, minVal, val - 1LL);
        root->right = buildBST(preorder, val + 1LL, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return buildBST(preorder, LLONG_MIN, LLONG_MAX);
    }
};

void inorderTraversal(TreeNode* root) {
    if (!root) return;
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

void preorderTraversal(TreeNode* root) {
    if (!root) return;
    cout << root->val << " ";
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}

int main() {
    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Solution sol;
    TreeNode* root = sol.bstFromPreorder(preorder);

    cout << "Inorder traversal (should be sorted): ";
    inorderTraversal(root);
    cout << endl;

    cout << "Preorder traversal (should match input): ";
    preorderTraversal(root);
    cout << endl;

    return 0;
}

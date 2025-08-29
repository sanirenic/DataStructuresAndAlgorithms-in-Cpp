#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

void postorderHelper(TreeNode* root, vector<int>& result) {
    if (!root) return;                      
    postorderHelper(root->left, result);
    postorderHelper(root->right, result);
    result.push_back(root->val);        
}

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> result;
    postorderHelper(root, result);
    return result;
}

int main() {
    
    TreeNode* root = new TreeNode(1);
    root->right = new TreeNode(2);
    root->right->left = new TreeNode(3);

    vector<int> res = postorderTraversal(root);

    cout << "Postorder Traversal: ";
    for (int x : res) cout << x << " ";
    cout << endl;
}

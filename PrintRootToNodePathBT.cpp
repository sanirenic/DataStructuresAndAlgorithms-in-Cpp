#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution{
    public:

    void dfs(TreeNode* root, vector<int> & path, vector<vector<int>> & res){
        if(!root) return;

        path.push_back(root->val);
        if(!root->left && !root->right){
            res.push_back(path);
        }
        else{
            dfs(root->left, path, res);
            dfs(root->right, path, res);
        }
        path.pop_back();
    }
    vector<vector<int>> binaryTreePaths(TreeNode* root){
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }
};

int main() {

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->right = new TreeNode(5);

    Solution sol;
    vector<vector<int>> paths = sol.binaryTreePaths(root);

    cout << "Root-to-Leaf Paths:" << endl;
    for (auto &path : paths) {
        for (int val : path) {
            cout << val << " ";
        }
        cout << endl;
    }

    delete root->left->right;
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
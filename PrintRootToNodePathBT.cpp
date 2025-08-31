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
        path.push_back();
    }
    vector<vector<int>> binaryTreePaths(TreeNode* root){
        vector<vector<int>> res;
        vector<int> path;
        dfs(root, path, res);
        return res;
    }
};
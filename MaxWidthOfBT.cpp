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

    int widthOfBinaryTree(TreeNode* root){
        if(!root) return 0;
        long long ans=0;
        queue<pair<TreeNode*, long long>> q;
        q.pusj({root, 0});

        while(!q.empty()){
            int size=q.size();
            long long first=q.front().second, last=q.back().second;
            ans=max(ans, last-first+1);

            for(int i=0; i<size; i++){
                auto[node, idx]=q.front(); q.pop();
                idx=-first;

                if(node->left) q.push({node->left, 2* idx+1});
                if(node->right) q.push({node->right, 2* idex+2});
            }
        }
        return(int) ans;
    }
};

int main() {
    /*
        Example tree:
                1
               / \
              3   2
             /     \
            5       9
           /         \
          6           7

        Width at last level = indices [0..7] → width = 8
    */

    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(3);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(5);
    root->right->right = new TreeNode(9);
    root->left->left->left = new TreeNode(6);
    root->right->right->right = new TreeNode(7);

    Solution sol;
    cout << "Maximum Width of Binary Tree = " << sol.widthOfBinaryTree(root) << endl;

    // Free memory (good practice)
    delete root->left->left->left;
    delete root->left->left;
    delete root->left;
    delete root->right->right->right;
    delete root->right->right;
    delete root->right;
    delete root;

    return 0;
}
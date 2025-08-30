#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<int> morrisPreorderTraversal(TreeNode* root){
    vector<int> result;
    TreeNode* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            result.push_back(curr->val);
            curr=curr->right;
        }
        else{
            TreeNode* pred=curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){
                result.push_back(curr->val);
                pred->right=curr;
                curr=curr->left;
            }
            else{
                pred->right=Null;
                curr=curr->right;
            }
        }
    }
    return result;
}

// Driver code
int main() {
    /*
            1
           / \
          2   3
         / \
        4   5
    */
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    vector<int> res = morrisPreorderTraversal(root);

        cout << "Morris Preorder Traversal: ";
    for (int x : res) cout << x << " ";
    cout << endl;
    return 0;
}


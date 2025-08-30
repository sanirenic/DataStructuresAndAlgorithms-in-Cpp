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
    vector<int> rightsideView(Node* root){
        vector<int> res;
        recursionRight(root, 0, res);
        return res;
    }
    vector<int> leftsideView(Node* root){
        vector<int> res;
        recursionLeft(root, 0, res);
        return res;
    }
    private:
    void recursionLeft(Node* root, int level, vector<int> &res){
        if(root==NULL){
            return;
        }
            if(res.size()==level){
                res.push_back(root->data);
            }
            recursionLeft(root->left, level+1, res);
            recursionLeft(root->right, level+1, res);
    }
    void recursionRight(Node* root, int level, vector<int>& res){
        if(root==NULL){
            return;
        }
        if(res.size()==level){
            res.push_back(root->data);
        
        recursionRight(root->right, level+1, res);
        recursionRight(root->left, level+1, res);
        }
    }
};

int main() {
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->right = new Node(10);
    root->right->left = new Node(9);

    Solution solution;

    vector<int> rightView = solution.rightsideView(root);

    cout << "Right View Traversal: ";
    for(auto node: rightView){
        cout << node << " ";
    }
    cout << endl;

    vector<int> leftView = solution.leftsideView(root);

    cout << "Left View Traversal: ";
    for(auto node: leftView){
        cout << node << " ";
    }
    cout << endl;

    return 0;
}
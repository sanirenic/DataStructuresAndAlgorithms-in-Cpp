#include <iostream>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    stack<TreeNode*> st;

    void pushLeft(TreeNode* node) {
        while (node) {
            st.push(node);
            node = node->left;
        }
    }

public:
    BSTIterator(TreeNode* root) {
        pushLeft(root);
    }

    int next() {
        TreeNode* node = st.top(); st.pop();
        int val = node->val;
        if (node->right) {
            pushLeft(node->right);
        }
        return val;
    }

    bool hasNext() {
        return !st.empty();
    }
};

// Helper function to build the BST manually
TreeNode* buildExampleTree() {
    // Tree structure:
    //       7
    //     /   \
    //    3     15
    //         /  \
    //        9    20

    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);
    return root;
}

int main() {
    TreeNode* root = buildExampleTree();
    BSTIterator iterator(root);

    while (iterator.hasNext()) {
        cout << iterator.next() << " ";
    }
    cout << endl;

    return 0;
}

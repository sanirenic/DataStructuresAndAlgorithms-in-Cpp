#include <iostream>
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
    int maxSum; 

    int maxPathDown(TreeNode* root) {
        if (!root) return 0;

        int left = max(0, maxPathDown(root->left));  
        int right = max(0, maxPathDown(root->right));

        maxSum = max(maxSum, left + right + root->val);

        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; 
        maxPathDown(root);
        return maxSum;
    }
};

int main() {

    TreeNode* root = new TreeNode(-10);
    root->left = new TreeNode(9);
    root->right = new TreeNode(20);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution sol;
    int result = sol.maxPathSum(root);

    cout << "Maximum Path Sum: " << result << endl;

    return 0;
}

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
    int maxSum; // global maximum

    int maxPathDown(TreeNode* root) {
        if (!root) return 0;

        // compute max path sum starting from left and right child
        int left = max(0, maxPathDown(root->left));   // ignore negative paths
        int right = max(0, maxPathDown(root->right));

        // path passing through root = left + root + right
        maxSum = max(maxSum, left + right + root->val);

        // return max path extending upwards
        return root->val + max(left, right);
    }

    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN; // handle negative values
        maxPathDown(root);
        return maxSum;
    }
};

// ----------- MAIN FUNCTION TO TEST -----------
int main() {
    /*
            -10
            /  \
           9   20
              /  \
             15   7
    */

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

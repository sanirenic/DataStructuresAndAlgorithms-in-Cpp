#include <bits/stdc++.h>
using namespace std;

// Definition of a Node in the Binary Tree
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) : data(val), left(NULL), right(NULL) {}
};

class Solution {
public:
    // Function to perform Vertical Order Traversal
    vector<vector<int>> verticalOrder(Node* root) {
        if (!root) return {};
        
        map<int, vector<int>> nodes;   // Horizontal Distance (HD) -> list of values
        queue<pair<Node*, int>> q;     // Node + HD
        q.push({root, 0});
        
        while (!q.empty()) {
            auto [node, hd] = q.front();
            q.pop();
            
            nodes[hd].push_back(node->data);
            
            if (node->left) q.push({node->left, hd - 1});
            if (node->right) q.push({node->right, hd + 1});
        }
        
        vector<vector<int>> result;
        for (auto& [hd, vals] : nodes) {
            result.push_back(vals);
        }
        return result;
    }
};

// Helper function to print result
void printVerticalOrder(const vector<vector<int>>& res) {
    for (const auto& level : res) {
        for (int val : level) {
            cout << val << " ";
        }
        cout << endl;
    }
}

// Example usage
int main() {
    /*
             1
           /   \
          2     3
         / \   / \
        4   5 6   7
               \   
                8
    */
    
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);
    root->right->left->right = new Node(8);
    
    Solution sol;
    vector<vector<int>> result = sol.verticalOrder(root);
    
    cout << "Vertical Order Traversal:\n";
    printVerticalOrder(result);

    return 0;
}

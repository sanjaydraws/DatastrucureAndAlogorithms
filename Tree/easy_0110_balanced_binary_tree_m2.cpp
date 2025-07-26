
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    bool isBalance = true;

    // compute height of tree in post-order manner
    // While computing height, we also check balance condition at every node
    int height(TreeNode* root) {
        // Base case: height of null node is 0
        if (root == nullptr) return 0;

        //  calculate height of left and right subtree
        int lh = height(root->left);
        int rh = height(root->right);

        // Check if current node is balanced:
        // i.e., height difference between left and right subtree ≤ 1
        if (isBalance && abs(lh - rh) > 1) {
            isBalance = false; // Tree is unbalanced, update flag
        }

        // Height of current node = max height of subtrees + 1
        return max(lh, rh) + 1;
    }

    // Main function to check if binary tree is height-balanced
    bool isBalanced(TreeNode* root) {
        height(root);  // Triggers height computation + balance check
        return isBalance;
    }
};
//  Time Complexity: O(N) — Each node visited once

// Space: O(H) — Max recursion stack = height of tree
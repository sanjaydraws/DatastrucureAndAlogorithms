//1382. Balance a Binary Search Tree
//https://leetcode.com/problems/balance-a-binary-search-tree/description/

class Solution {
public:
    // Approach: Inorder Traversal + Build Balanced BST from Sorted Array
    // Time Complexity: O(N) — for both inorder traversal and building tree
    // Space Complexity: O(N) — to store inorder nodes in vector + recursion stack

    // Step 1: Store inorder traversal of BST (sorted order)
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (!root) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

    // Step 2: Recursively build balanced BST from sorted array
    TreeNode* buildBalancedTree(vector<int>& nodes, int left, int right) {
        if (left > right) return nullptr;

        int mid = (left + right) / 2;
        TreeNode* root = new TreeNode(nodes[mid]);

        root->left = buildBalancedTree(nodes, left, mid - 1);
        root->right = buildBalancedTree(nodes, mid + 1, right);
        return root;
    }

    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);  // O(N) — Collect sorted nodes
        return buildBalancedTree(nodes, 0, nodes.size() - 1);  // O(N) — Build balanced BST
    }
};

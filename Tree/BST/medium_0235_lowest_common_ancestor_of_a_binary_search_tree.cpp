/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

    // Approach 1: Recursive
    /*
        Logic:
        - If both p and q < root → go left
        - If both p and q > root → go right
        - Else, root is split point → LCA

        Time Complexity: O(logN) avg, O(N) worst (unbalanced BST)
        Space Complexity: O(H) for recursion stack (H = height of tree)
    */
    TreeNode* lowestCommonAncestorRecursive(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (!root) return nullptr;

        // Both nodes lie on left
        if (p->val < root->val && q->val < root->val)
            return lowestCommonAncestorRecursive(root->left, p, q);

        // Both nodes lie on right
        if (p->val > root->val && q->val > root->val)
            return lowestCommonAncestorRecursive(root->right, p, q);

        // Nodes are on different sides → current is LCA
        return root;
    }

    // Approach 2: Iterative
    /*
        Logic same as above — BST property based search
        - Traverse down until split point found

        Time Complexity: O(logN) avg, O(N) worst
        Space Complexity: O(1)
    */
    TreeNode* lowestCommonAncestorIterative(TreeNode* root, TreeNode* p, TreeNode* q) {
        while (root) {
            if (p->val < root->val && q->val < root->val)
                root = root->left; // Both in left
            else if (p->val > root->val && q->val > root->val)
                root = root->right; // Both in right
            else
                return root; // This is the LCA (split point)
        }
        return nullptr;
    }
};

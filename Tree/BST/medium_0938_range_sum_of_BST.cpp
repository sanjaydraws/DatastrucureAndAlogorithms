//https://leetcode.com/problems/range-sum-of-bst/submissions/
// 938. Range Sum of BST
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    // Function to return the sum of all node values within the range [low, high]
    int rangeSumBST(TreeNode* root, int low, int high) {
        if (!root) return 0;

        // If current node's value lies in the range, include it and check both subtrees
        if (root->val >= low && root->val <= high)
            return root->val 
                + rangeSumBST(root->left, low, high) 
                + rangeSumBST(root->right, low, high);

        // If current value is less than low, skip left subtree
        if (root->val < low)
            return rangeSumBST(root->right, low, high);

        // If current value is greater than high, skip right subtree
        return rangeSumBST(root->left, low, high);
    }
};

/*
Time Complexity:  O(n)
    - In the worst case, we might visit all nodes if all lie within the range.
    - For a balanced BST with fewer nodes in range, it could be closer to O(log n).

Space Complexity: O(h)
    - Due to recursion stack, where h = height of BST.
    - In worst case (skewed tree), space = O(n). In balanced tree, space = O(log n).
*/

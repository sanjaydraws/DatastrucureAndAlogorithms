class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        // Base case: empty tree
        if (root == nullptr) return false;

        // Leaf node check
        if (root->left == nullptr && root->right == nullptr) {
            return root->val == targetSum;
        }

        // Recursive check on left and right
        int remainingSum = targetSum - root->val;
        return hasPathSum(root->left, remainingSum) || hasPathSum(root->right, remainingSum);
    }
};

/*
Time Complexity: O(N)
    - Every node is visited once in the worst case.

Space Complexity: O(H)
    - H = height of the tree.
    - In worst case (skewed tree), H = N, so O(N).
    - In balanced tree, H = logN, so O(logN).
    - This is due to recursion stack.
*/

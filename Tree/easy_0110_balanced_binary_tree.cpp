class Solution {
public:
    //  Helper function to calculate the height of the tree
    int height(TreeNode* root) {
        // Base case: empty subtree has height 0
        if (root == nullptr) return 0;

        // Recursively calculate the height of left and right subtrees
        return max(height(root->left), height(root->right)) + 1;
    }

    //  Main function to check if the binary tree is height-balanced
    bool isBalanced(TreeNode* root) {
        // Base case: empty tree is balanced
        if (root == nullptr) return true;

        // Calculate the height of left and right subtrees
        int leftH = height(root->left);
        int rightH = height(root->right);

        // Check if the current node is balanced (height diff ≤ 1)
        bool currNodeAns = abs(leftH - rightH) <= 1;

        // Recursively check if left and right subtrees are also balanced
        bool leftAns = isBalanced(root->left);
        bool rightAns = isBalanced(root->right);

        // Return true only if current node, left, and right subtrees are balanced
        return currNodeAns && leftAns && rightAns;
    }
};

/*
Time Complexity: O(N^2)
    - In the worst case, for each node we are computing height (O(N) per node).
    - So, total time becomes O(N * N) in skewed trees.

 Space Complexity: O(H)
    - Due to recursion stack, where H = height of the tree.
    - In the worst case (skewed tree), H = N → O(N)
    - In the best case (balanced tree), H = logN → O(logN)
*/

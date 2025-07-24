class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        //  Base Case: if current node is null or matches either p or q
        if (root == nullptr || root == p || root == q) {
            return root;
        }

        //  Recur for left and right subtrees
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        //  Case 1: If both left and right return non-null → this node is LCA
        if (leftLCA != nullptr && rightLCA != nullptr) {
            return root;
        }

        //  Case 2: Return the non-null side (if any)
        return (leftLCA != nullptr) ? leftLCA : rightLCA;
    }
};

/*
⏱Time Complexity: O(N)
    - Each node is visited once in a post-order traversal.
    - N = total number of nodes in the tree.

 Space Complexity: O(H)
    - Due to recursive stack space where H = height of the tree.
    - Worst case (skewed tree): O(N)
    - Best case (balanced tree): O(log N)
*/

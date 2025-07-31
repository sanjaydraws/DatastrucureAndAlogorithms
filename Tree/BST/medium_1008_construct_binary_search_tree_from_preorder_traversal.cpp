//1008. Construct Binary Search Tree from Preorder Traversal
//https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/description/
class Solution {
public:
    // Helper function to build BST from preorder using bounds
    TreeNode* build(vector<int>& preorder, int& index, int minVal, int maxVal) {
        // Base case: All elements processed or current value is out of the valid range
        if (index >= preorder.size() || preorder[index] < minVal || preorder[index] > maxVal)
            return nullptr;

        // Current value is valid, create node
        int val = preorder[index++];
        TreeNode* root = new TreeNode(val);

        // Recursively build left and right subtrees
        // Left subtree must have values in range [minVal, val)
        root->left = build(preorder, index, minVal, val);

        // Right subtree must have values in range [val, maxVal]
        root->right = build(preorder, index, val, maxVal);

        return root;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return build(preorder, index, INT_MIN, INT_MAX);
    }
};

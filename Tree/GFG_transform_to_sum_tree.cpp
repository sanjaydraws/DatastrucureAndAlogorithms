class Solution {
public:
    int toSumTree(Node* node) {
        if (node == nullptr) return 0;

        int old_val = node->data;

        // Recursively convert left and right subtrees
        int leftSum = toSumTree(node->left);
        int rightSum = toSumTree(node->right);

        // Set current node's data to sum of left and right subtree
        node->data = leftSum + rightSum;

        // Return total sum including old value for parent's computation
        return node->data + old_val;
    }

    void transformTree(Node* root) {
        toSumTree(root);
    }
};

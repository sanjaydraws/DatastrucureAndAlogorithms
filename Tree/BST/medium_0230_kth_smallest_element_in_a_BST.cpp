class Solution {
public:
    // ✅ 1. Recursive Inorder Traversal without external counter
    // T.C = O(H + k), where H = height of tree, worst O(N)
    // S.C = O(H) due to recursion stack
    int kthSmallestRecursive(TreeNode* root, int k) {
        return inorder(root, k);
    }

    int inorder(TreeNode* node, int& k) {
        if (!node) return -1;

        // Traverse left subtree
        int left = inorder(node->left, k);
        if (k == 0) return left;

        // Visit current node
        k--;
        if (k == 0) return node->val;

        // Traverse right subtree
        return inorder(node->right, k);
    }

    // ✅ 2. Morris Inorder Traversal (No recursion or stack)
    // T.C = O(N), S.C = O(1) — space efficient
    int kthSmallestMorris(TreeNode* root, int k) {
        TreeNode* curr = root;
        int count = 0;

        while (curr) {
            if (!curr->left) {
                // Visit current node
                count++;
                if (count == k) return curr->val;
                curr = curr->right;
            } else {
                // Find the inorder predecessor
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr)
                    pred = pred->right;

                if (!pred->right) {
                    // Threading - temporary link back to current node
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove the thread
                    pred->right = nullptr;
                    count++;
                    if (count == k) return curr->val;
                    curr = curr->right;
                }
            }
        }

        return -1;
    }
};

class Solution {
public:
    int ans = -1;

    // Helper function to perform DFS and find target node
    bool dfs(TreeNode* root, int& k, int target) {
        if (root == nullptr) return false;

        if (root->val == target) return true;

        // Search in left and right subtrees
        bool left = dfs(root->left, k, target);
        bool right = dfs(root->right, k, target);

        // If target found in either subtree
        if (left || right) {
            k--;
            if (k == 0) {
                ans = root->val;  // K-th ancestor found
                return false;     // stop further backtracking
            }
            return true;
        }

        return false; // target not found in this path
    }

    int kthAncestor(TreeNode* root, int k, int target) {
        dfs(root, k, target);
        return ans;
    }
};

/*
Time Complexity: O(N)
    - We visit each node at most once.

Space Complexity: O(H)
    - Due to recursion stack where H = height of tree.
    - Worst case (skewed tree): O(N), best case (balanced tree): O(logN)
*/

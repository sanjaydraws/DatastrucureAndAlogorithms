//653. Two Sum IV - Input is a BST
//https://leetcode.com/problems/two-sum-iv-input-is-a-bst/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
public:
    //  Approach 1: DFS + HashSet
    // T.C: O(n), S.C: O(n)
    // Traverse the tree and check if (k - current_node_val) is already seen
    unordered_set<int> seen;

    bool dfs(TreeNode* node, int k) {
        if (!node) return false;

        // Check if complement exists
        if (seen.count(k - node->val)) return true;

        // Insert current node value
        seen.insert(node->val);

        // Search in left and right subtree
        return dfs(node->left, k) || dfs(node->right, k);
    }

    //  Approach 2: Inorder Traversal + Two Pointers
    // T.C: O(n), S.C: O(n)
    // Convert BST into sorted array using inorder traversal, then apply two sum
    void inorder(TreeNode* root, vector<int>& vals) {
        if (!root) return;
        inorder(root->left, vals);
        vals.push_back(root->val); // store node value
        inorder(root->right, vals);
    }

    bool twoPointer(vector<int>& vals, int k) {
        int left = 0, right = vals.size() - 1;
        while (left < right) {
            int sum = vals[left] + vals[right];
            if (sum == k) return true;
            else if (sum < k) left++;
            else right--;
        }
        return false;
    }

    //  Wrapper: You can choose which approach to use
    bool findTarget(TreeNode* root, int k) {
        //  Uncomment this line to use DFS + HashSet approach:
        // seen.clear();
        // return dfs(root, k);

        //  Use Inorder + Two Pointer:
        vector<int> vals;
        inorder(root, vals);
        return twoPointer(vals, k);
    }
};

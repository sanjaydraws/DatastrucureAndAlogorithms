class TreeNode {
public:
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int value) : val(value), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> result;
        vector<int> path;
        dfs(root, targetSum, path, result);
        return result;
    }

private:
    void dfs(TreeNode* root, int targetSum, vector<int>& path, vector<vector<int>>& result) {
        if (root == nullptr) return;

        path.push_back(root->val);

        // Leaf node and valid path sum
        if (root->left == nullptr && root->right == nullptr) {
            if (root->val == targetSum) {
                result.push_back(path);
            }
        }

        dfs(root->left, targetSum - root->val, path, result);
        dfs(root->right, targetSum - root->val, path, result);

        path.pop_back(); // Backtrack
    }
};

/*
Time Complexity: O(N^2)
    - In the worst case, we visit every node once (O(N)).
    - For each leaf path, we may copy a path of length O(N) to the result.
    - So overall: O(N^2) in worst case.

Space Complexity: O(N)
    - Recursion stack in worst case is O(N) (skewed tree).
    - Path vector stores at most O(N) elements.
    - Result vector can grow to O(N) paths with O(N) size each in worst case, but this is considered output space.
*/

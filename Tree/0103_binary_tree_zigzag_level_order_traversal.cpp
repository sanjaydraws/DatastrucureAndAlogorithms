class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if (!root) return result;

        queue<TreeNode*> q;
        q.push(root);
        bool leftToRight = true; // Flag to track current direction

        while (!q.empty()) {
            int levelSize = q.size();
            vector<int> level(levelSize); // Store current level nodes

            for (int i = 0; i < levelSize; ++i) {
                TreeNode* node = q.front(); q.pop();

                // Determine correct index based on direction
                int index = leftToRight ? i : (levelSize - 1 - i);
                level[index] = node->val;

                // Push child nodes for next level
                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }

            result.push_back(level);
            leftToRight = !leftToRight; // Toggle direction for next level
        }

        return result;
    }
};

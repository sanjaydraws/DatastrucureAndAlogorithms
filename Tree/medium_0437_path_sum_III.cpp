// https://leetcode.com/problems/path-sum-iii/description/
//437. Path Sum III

// Approach 1: Brute Force DFS

/*
Time Complexity: O(N^2) in worst case (like skewed tree)
Space Complexity: O(H) for recursion stack (H = height of tree)
*/

class BruteForce {
public:
    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return 0;

        // Root se start hone wale path count karo
        int selfPaths = countFrom(root, targetSum);

        // Left aur right subtree se recursively call karo
        return selfPaths + pathSum(root->left, targetSum) + pathSum(root->right, targetSum);
    }

private:
    int countFrom(TreeNode* node, long long sum) {
        if (!node) return 0;

        int count = 0;
        if (node->val == sum) count++;

        // Aage dono child pe jao
        count += countFrom(node->left, sum - node->val);
        count += countFrom(node->right, sum - node->val);

        return count;
    }
};


// Approach 2: Prefix Sum + Backtracking
class Solution {
public:
    int count = 0;

    void dfs(TreeNode* node, long long currSum, int targetSum, unordered_map<long long, int>& prefix) {
        if (!node) return;

        currSum += node->val;
        // Check if there's a prefix that gives us targetSum

        if (prefix.count(currSum - targetSum)) {
            count += prefix[currSum - targetSum];
        }

        prefix[currSum]++;
        dfs(node->left, currSum, targetSum, prefix);
        dfs(node->right, currSum, targetSum, prefix);
        prefix[currSum]--; // Backtrack
    }

    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1; // Base case: prefix sum zero
        dfs(root, 0, targetSum, prefix);
        return count;
    }
};

/*
Time Complexity: O(N)
Space Complexity: O(N) for hashmap and recursion stack
*/
// =============================================================

//Approach 3: Path Vector from Root to Node
class PathVector {
public:
    int pathSum(TreeNode* root, int targetSum) {
        count = 0;
        path.clear();
        dfs(root, targetSum);
        return count;
    }

private:
    int count;
    vector<int> path;

    void dfs(TreeNode* node, int target) {
        if (!node) return;

        path.push_back(node->val);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; --i) {
            sum += path[i];
            if (sum == target) count++;
        }

        dfs(node->left, target);
        dfs(node->right, target);

        path.pop_back(); // Backtrack
    }
};

/*
Time Complexity: O(N^2) in worst case (due to path loop)
Space Complexity: O(H) for recursion + O(H) for path vector
*/

// https://leetcode.com/problems/permutations-ii/description/
// 47. Permutations II
#include <vector>
#include <algorithm>  // for sort()

using namespace std;

class Solution {
public:
    // Recursive helper to generate unique permutations
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        // Base case: when path has all elements, store the permutation
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // Try placing every number that hasn't been used yet
        for (int i = 0; i < nums.size(); i++) {
            // If the current element is already used in this path, skip it
            if (used[i]) continue;

            // Skip duplicates:
            // If current num is same as previous AND previous is not used in this path → skip
            // (To avoid starting same branch from a later duplicate)
            if (i > 0 && nums[i] == nums[i - 1] && !used[i - 1]) continue;

            // Choose current element
            used[i] = true;
            path.push_back(nums[i]);

            // Recurse to next level
            backtrack(nums, used, path, result);

            // Backtrack: undo the choice
            path.pop_back();
            used[i] = false;
        }
    }

    // Main function to be called externally to generate permutations
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> used(nums.size(), false);  // Track used elements

        // Sort is necessary to bring duplicates together for skipping logic
        sort(nums.begin(), nums.end());

        // Start backtracking
        backtrack(nums, used, path, result);
        return result;
    }
};

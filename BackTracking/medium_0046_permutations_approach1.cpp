//https://leetcode.com/problems/permutations/
//46. Permutations

// Permutations Using Backtracking (used[] + path[])

#include <iostream>
#include <vector>

using namespace std;

/*
    Time Complexity: O(n × n!)
    --------------------------
    - There are n! total permutations.
    - For each permutation, we build a path of size n (which takes O(n) time).
    - So total time = O(n × n!)

    Space Complexity: O(n) + O(n!) = O(n!)
    --------------------------------------
    - O(n): recursion stack and 'used' array
    - O(n!): to store all permutations in the result vector
*/

class Solution {
public:
    // Helper function to perform backtracking
    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path, vector<vector<int>>& result) {
        // Base case: if path is full, we found a complete permutation
        if (path.size() == nums.size()) {
            result.push_back(path);
            return;
        }

        // Try each number that hasn’t been used yet
        for (int i = 0; i < nums.size(); i++) {
            // Skip if this number is already used in the current path
            if (used[i]) continue;

            // Choose the number
            used[i] = true;
            path.push_back(nums[i]);

            // Recurse to build the next level
            backtrack(nums, used, path, result);

            // Undo (Backtrack): remove last number and mark it as unused
            path.pop_back();
            used[i] = false;
        }
    }

    // Main function to start the permutation generation
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;              // Stores all permutations
        vector<int> path;                        // Current path being built
        vector<bool> used(nums.size(), false);   // Marks which elements are used
        backtrack(nums, used, path, result);
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};

    vector<vector<int>> permutations = obj.permute(nums);

    cout << "All permutations:\n";
    for (const auto& p : permutations) {
        for (int num : p) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

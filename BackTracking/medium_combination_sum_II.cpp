// https://leetcode.com/problems/combination-sum-ii/description/
// 40. Combination Sum II



#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Recursive backtracking function
    void backtrack(int start, int target, vector<int>& path, vector<vector<int>>& result, vector<int>& candidates) {
        // Base case: valid combination found
        if (target == 0) {
            result.push_back(path);
            return;
        }

        // Explore all candidates starting from 'start' index
        for (int i = start; i < candidates.size(); ++i) {

            // Skip duplicate values at the same recursion level to avoid duplicate combinations
            if (i > start && candidates[i] == candidates[i - 1]) continue;

            // Stop exploring if current number is greater than the remaining target
            // Since array is sorted, no further values can be used
            if (candidates[i] > target) break;

            // Choose the current number
            path.push_back(candidates[i]);

            // Recurse with next index (i + 1), because we can only use each number once
            backtrack(i + 1, target - candidates[i], path, result, candidates);

            // Backtrack: remove last chosen number and explore other paths
            path.pop_back();
        }
    }

    // Main function to call backtracking and return all unique combinations
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        // Step 1: Sort to bring duplicates together and enable pruning
        sort(candidates.begin(), candidates.end());

        vector<vector<int>> result;  // Stores all valid combinations
        vector<int> path;            // Stores current path (partial combination)

        backtrack(0, target, path, result, candidates);  // Start backtracking

        return result;
    }
};

int main() {
    vector<int> candidates = {1, 1, 2, 5};
    int target = 6;

    // Run the combination sum II algorithm
    Solution sol;
    vector<vector<int>> result = sol.combinationSum2(candidates, target);

    // Print result
    cout << "Unique combinations that sum to " << target << ":\n";
    for (auto& comb : result) {
        cout << "[ ";
        for (int num : comb) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}


/**

Time Complexity: `O(2^n * k + n log n)`

`O(n log n)` — for sorting the candidates.
`O(2^n)` — each element is either picked or skipped (subset-style recursion).
`O(k)` — time to copy each valid combination to the result.

 So:
`O(2^n * k + n log n)`**



Space Complexity: `O(k * C + n)`

 `O(k * C)` — to store all valid combinations (`C` = number of results).
 `O(n)` — recursion call stack and temporary path.

 So:
`O(k * C + n)`**
/

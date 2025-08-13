https://leetcode.com/problems/subsets-ii/description/
//90. Subsets II

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Main function to return all unique subsets
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // Step 1: Sort the input array to bring duplicates together
        sort(nums.begin(), nums.end());

        vector<vector<int>> res;  // Final result to store all subsets
        vector<int> path;         // Current subset (path) being built

        // Step 2: Start the backtracking process
        solve(0, path, res, nums);

        return res;
    }

    // Helper function for backtracking
    void solve(int index, vector<int>& path, vector<vector<int>>& res, vector<int>& nums) {
        // Add the current subset (path) to the result
        res.push_back(path);

        // Step 3: Iterate over elements starting from 'index'
        for (int i = index; i < nums.size(); i++) {
            // Step 4: Skip duplicate elements on the same recursion level
            // This ensures we do not include the same subset more than once
            if (i > index && nums[i] == nums[i - 1]) continue;

            // Step 5: Choose the current number
            path.push_back(nums[i]);

            // Step 6: Recurse with next index
            solve(i + 1, path, res, nums);

            // Step 7: Backtrack to explore other combinations
            path.pop_back();
        }
    }
};

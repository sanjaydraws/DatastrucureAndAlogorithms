// 698. Partition to K Equal Sum Subsets
// https://leetcode.com/problems/partition-to-k-equal-sum-subsets/description/

class Solution {
public:
    // Main function to determine if we can partition nums into k equal sum subsets
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int totalSum = accumulate(nums.begin(), nums.end(), 0);

        // If total sum is not divisible by k, it's impossible to divide equally
        if (totalSum % k != 0) return false;

        int target = totalSum / k;

        vector<bool> visited(nums.size(), false);  // To track which numbers are used

        // Sorting in reverse makes backtracking faster (start from bigger elements)
        sort(nums.rbegin(), nums.rend());

        return backtrack(nums, visited, k, 0, 0, target);
    }

    // Recursive backtracking function
    bool backtrack(vector<int>& nums, vector<bool>& visited, int k, int startIndex, int currSum, int target) {
        // If we have only 1 subset left, rest of the elements must form it correctly
        if (k == 1) return true;

        // Current subset completed, move on to next one
        if (currSum == target)
            return backtrack(nums, visited, k - 1, 0, 0, target);

        // Try to fill current subset from available numbers
        for (int i = startIndex; i < nums.size(); i++) {
            if (visited[i]) continue;  // Already used
            if (currSum + nums[i] > target) continue;  // Exceeds target sum

            // Choose
            visited[i] = true;

            // Recurse to next level
            if (backtrack(nums, visited, k, i + 1, currSum + nums[i], target))
                return true;

            // Backtrack (undo choice)
            visited[i] = false;
        }

        // No valid subset configuration found
        return false;
    }
};

/*
Time Complexity: O(k * 2^n)
- Each number can be tried in different subsets
- Exponential due to backtracking
- Pruned by skipping over visited elements and overshooting sums

Space Complexity: O(n)
- visited[] array of size n
- recursion call stack can go up to depth n
*/

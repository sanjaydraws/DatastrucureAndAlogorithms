
//https://leetcode.com/problems/minimum-path-sum/description/
//64. Minimum Path Sum

#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:

    // Recursive Approach
    // Explore all paths from (0,0) to (i,j) and take the one with minimum cost
    // Time: Exponential (2^(m*n)), very slow for large grids
    // Space: O(m + n) due to recursion stack
    int recursive(int i, int j, vector<vector<int>>& grid) {
        if (i < 0 || j < 0) return INT_MAX;  // Out of bounds, return max to avoid choosing this path
        if (i == 0 && j == 0) return grid[0][0];  // Reached starting point

        // Try moving from top and left
        int up = recursive(i - 1, j, grid);
        int left = recursive(i, j - 1, grid);

        return grid[i][j] + min(up, left);
    }

    // Memoization (Top-down DP)
    // Same logic as recursion, but store intermediate results to avoid recomputation
    // Time: O(m * n), Space: O(m * n) + stack space
    int memo(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp) {
        if (i < 0 || j < 0) return INT_MAX;
        if (i == 0 && j == 0) return grid[0][0];

        if (dp[i][j] != -1) return dp[i][j];  // Already computed

        int up = memo(i - 1, j, grid, dp);
        int left = memo(i, j - 1, grid, dp);

        return dp[i][j] = grid[i][j] + min(up, left);
    }

    // Tabulation (Bottom-up DP)
    // Build the solution from (0,0) to (m-1,n-1) iteratively
    // Time: O(m * n), Space: O(m * n)
    int tabulation(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int>(n));

        // Starting point
        dp[0][0] = grid[0][0];

        // Fill first row (can only come from left)
        for (int j = 1; j < n; j++) {
            dp[0][j] = grid[0][j] + dp[0][j - 1];
        }

        // Fill first column (can only come from top)
        for (int i = 1; i < m; i++) {
            dp[i][0] = grid[i][0] + dp[i - 1][0];
        }

        // Fill the rest of the grid
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                // You can reach cell (i,j) either from top or left
                dp[i][j] = grid[i][j] + min(dp[i - 1][j], dp[i][j - 1]);
            }
        }

        return dp[m - 1][n - 1];  // Minimum cost to reach bottom-right corner
    }

    // Space Optimized DP
    // Instead of full 2D dp, use a single 1D array to store results row-wise
    // Time: O(m * n), Space: O(n)
    int spaceOptimized(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> dp(n);  // dp[j] = min cost to reach cell in current row

        // Fill first row
        dp[0] = grid[0][0];
        for (int j = 1; j < n; j++) {
            dp[j] = grid[0][j] + dp[j - 1];
        }

        // Process remaining rows
        for (int i = 1; i < m; i++) {
            dp[0] += grid[i][0];  // First column (can only come from above)
            for (int j = 1; j < n; j++) {
                // Minimum of coming from above (dp[j]) or from left (dp[j - 1])
                dp[j] = grid[i][j] + min(dp[j], dp[j - 1]);
            }
        }

        return dp[n - 1];  // Last element contains the result
    }

    // Wrapper function to call any desired approach
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();


        // Recursive (not recommended for large input)
        // return recursive(m - 1, n - 1, grid);

        // Memoization
        // vector<vector<int>> dp(m, vector<int>(n, -1));
        // return memo(m - 1, n - 1, grid, dp);

        // Tabulation
        // return tabulation(grid);

        // Space Optimized
        return spaceOptimized(grid);
    }
};

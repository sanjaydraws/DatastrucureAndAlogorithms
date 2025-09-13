// Approach: Brute Force DFS (Try all possible moves for both robots)
//
// Idea:
// - 2 robots start from top row:
//      Robot1 → (0,0)
//      Robot2 → (0, n-1)
// - Each row, both robots can move to 3 directions: left, down, right
//   → So total 9 combinations per row
// - Collect cherries at current positions (avoid double counting if same cell)
// - Explore recursively all paths and take the maximum cherries
// - Base case: if reached last row → return cherries collected
// - Out of bounds → return a very negative number (-1e9) so path ignored
//
// Limitation: This brute force explores all states → exponential time
//             (TLE for large grid), needs DP memoization for optimization.

//Time Complexity: O(9^m) (exponential, 9 choices per row × m rows)
// Space Complexity: O(m) (recursion stack)
class Solution {
public:
    int m, n;
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();        // rows
        n = grid[0].size();     // cols
        // Start DFS: Robot1 at col=0, Robot2 at col=n-1
        return dfs(0, 0, n - 1, grid);
    }

    int dfs(int row, int c1, int c2, vector<vector<int>>& grid) {
        // Out of bounds check
        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return -1e9;

        // Cherries collected at this row
        int cherries = grid[row][c1];
        if (c1 != c2) cherries += grid[row][c2]; // avoid double count

        // Base case: if we are at the last row
        if (row == m - 1) return cherries;

        int maxi = -1e9;
        // Try all 9 possible moves for (c1, c2)
        for (int dc1 = -1; dc1 <= 1; dc1++) {
            for (int dc2 = -1; dc2 <= 1; dc2++) {
                maxi = max(maxi, dfs(row + 1, c1 + dc1, c2 + dc2, grid));
            }
        }

        return cherries + maxi;
    }
};

/*
🔎 Approach: Recursion + Memoization (Top-down DP)

Time Complexity: O(m * n * n * 9) ≈ O(m * n^2)
   - States = m * n * n  (row, c1, c2)
   - Each state explores 9 possible moves

 Space Complexity: O(m * n * n) for dp + O(m) recursion stack
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int m, n;
    vector<vector<vector<int>>> dp; // 3D dp[row][c1][c2]

    int dfs(int row, int c1, int c2, vector<vector<int>>& grid) {
        // Out of boundary
        if (c1 < 0 || c2 < 0 || c1 >= n || c2 >= n) return -1e9;

        //  Already computed
        if (dp[row][c1][c2] != -1) return dp[row][c1][c2];

        //  Collect cherries from current row
        int cherries = grid[row][c1];
        if (c1 != c2) cherries += grid[row][c2]; // avoid double count

        //  Base case → last row
        if (row == m - 1) return dp[row][c1][c2] = cherries;

        //  Explore 9 moves (3 choices each robot)
        int maxi = -1e9;
        for (int dc1 = -1; dc1 <= 1; dc1++) {
            for (int dc2 = -1; dc2 <= 1; dc2++) {
                maxi = max(maxi, dfs(row + 1, c1 + dc1, c2 + dc2, grid));
            }
        }

        return dp[row][c1][c2] = cherries + maxi;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();

        // initialize dp with -1
        dp.assign(m, vector<vector<int>>(n, vector<int>(n, -1)));

        return dfs(0, 0, n - 1, grid); // start robots at (0,0) & (0,n-1)
    }
};

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

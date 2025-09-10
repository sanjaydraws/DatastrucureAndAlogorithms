// 741. Cherry Pickup
// https://leetcode.com/problems/cherry-pickup/description/



#include <bits/stdc++.h>
using namespace std;

//Approach: 1: brute force/backtracking
class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // If no valid path exists, return 0
        return max(0, cherryCollect(n, grid, 0, 0, 0, 0));
    }

private:
    int cherryCollect(int n, vector<vector<int>>& grid, int r1, int c1, int r2, int c2) {
        // Out of bounds or thorn (-1) → invalid path
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n || grid[r1][c1] == -1 || grid[r2][c2] == -1)
            return INT_MIN;

        // If either person reaches the bottom-right corner
        if(r1 == n-1 && c1 == n-1) return grid[r1][c1];
        if(r2 == n-1 && c2 == n-1) return grid[r2][c2];

        // Collect cherries (avoid double count if both are on the same cell)
        int cherries;
        if(r1 == r2 && c1 == c2)
            cherries = grid[r1][c1];
        else
            cherries = grid[r1][c1] + grid[r2][c2];

        // Explore 4 possibilities:
        // 1. Both move down
        // 2. P1 moves down, P2 moves right
        // 3. P1 moves right, P2 moves down
        // 4. Both move right
        cherries += max({
            cherryCollect(n, grid, r1+1, c1, r2+1, c2),
            cherryCollect(n, grid, r1+1, c1, r2, c2+1),
            cherryCollect(n, grid, r1, c1+1, r2+1, c2),
            cherryCollect(n, grid, r1, c1+1, r2, c2+1)
        });

        return cherries;
    }
};

/*
-----------------------------------------
Time Complexity:
- Each person can move 2 ways (down, right).
- Together → 4 recursive calls per state.
- Without memoization → Exponential growth.
- Worst-case ≈ O(4^(2N)) → will cause TLE for large N.

Space Complexity:
- Recursion depth = O(2N) (path length).
- So, auxiliary stack space = O(N).
- No extra DP/memo table used.
-----------------------------------------
*/


// ==================================================



// Top-Down DP with Memoization
/*
-----------------------------------------------------
 Approach: 2
- Convert 2 trips into 2 persons starting from (0,0) → (n-1,n-1) simultaneously.
- Both take same number of steps, so c2 = r1+c1-r2.
- Use recursion + memoization (3D DP) to store states.
- At each step, try 4 move combinations (Down/Right for both).
- Collect cherries → if both on same cell count once.

-----------------------------------------------------
Time Complexity (T.C.): O(n^3)
- States = r1 * c1 * r2 = O(n^3)
- Each state computed once.

Space Complexity (S.C.): O(n^3) 
- For DP table.
- Recursion stack depth = O(n).

-----------------------------------------------------
*/

class Solution2 {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        // 3D DP: dp[r1][c1][r2] → max cherries collected
        // when person1 is at (r1,c1) and person2 is at (r2,c2)
        // NOTE: c2 is derived → c2 = r1 + c1 - r2
        vector<vector<vector<int>>> dp(n, vector<vector<int>>(n, vector<int>(n, -1)));

        // call recursive function (Top-Down DP)
        return max(0, cheryCollect(n, grid, dp, 0, 0, 0));
    }

private: 
    // Recursive helper function
    int cheryCollect(int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp,
                     int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2; // because steps taken by both are same → r1+c1 = r2+c2

        //  Out of bounds OR thorn (-1 cell) → invalid path
        if (r1 >= n || r2 >= n || c1 >= n || c2 >= n 
            || grid[r1][c1] == -1 || grid[r2][c2] == -1) {
            return -1e9; // return -INF so this path is not chosen
        }

        //  Already computed → use memoized result
        if (dp[r1][c1][r2] != -1) return dp[r1][c1][r2];

        //  Base case: If person1 reaches bottom-right → person2 भी वहीं होगा
        if (r1 == n - 1 && c1 == n - 1) return grid[r1][c1];

        //  Current cherries picked
        int cherries = (r1 == r2 && c1 == c2) 
                        ? grid[r1][c1]                    // same cell → count once
                        : grid[r1][c1] + grid[r2][c2];    // different cells → add both

        //  Explore 4 possibilities (both move Down/Right in combinations)
        int bestCherries = max({
            cheryCollect(n, grid, dp, r1 + 1, c1, r2 + 1), // person1 Down, person2 Down
            cheryCollect(n, grid, dp, r1 + 1, c1, r2),     // person1 Down, person2 Right
            cheryCollect(n, grid, dp, r1, c1 + 1, r2 + 1), // person1 Right, person2 Down
            cheryCollect(n, grid, dp, r1, c1 + 1, r2)      // person1 Right, person2 Right
        });

        //  Memoize and return result
        return dp[r1][c1][r2] = cherries + bestCherries;
    }
};

// https://leetcode.com/problems/strange-printer/description/
// 664. Strange Printer
#include <iostream>
#include <vector>
#include <string>
#include <climits>
using namespace std;

class Solution {
public:

    //  1. Pure Recursive Approach
    // Goal: Print s[i..j] using minimum operations
    int solveRecursive(string &s, int i, int j) {
        // Base case: no characters to print
        if (i > j) return 0;

        // Single character requires 1 operation
        if (i == j) return 1;

        // Worst case: print s[i] separately, then solve for i+1 to j
        int res = solveRecursive(s, i + 1, j) + 1;

        // Try to merge print jobs if s[i] matches s[k]
        for (int k = i + 1; k <= j; ++k) {
            if (s[k] == s[i]) {
                // Print s[i] along with s[k], and divide problem
                res = min(res, solveRecursive(s, i, k - 1) + solveRecursive(s, k + 1, j));
            }
        }

        return res;
    }

    //  2. Memoization (Top-down DP)
    int solveMemo(string &s, int i, int j, vector<vector<int>> &dp) {
        // Base cases same as recursion
        if (i > j) return 0;
        if (i == j) return 1;

        // Already solved?
        if (dp[i][j] != -1) return dp[i][j];

        // Worst case: print s[i] separately, then solve for rest
        int res = solveMemo(s, i + 1, j, dp) + 1;

        // Try to combine same characters at k to reduce ops
        for (int k = i + 1; k <= j; ++k) {
            if (s[k] == s[i]) {
                res = min(res, solveMemo(s, i, k - 1, dp) + solveMemo(s, k + 1, j, dp));
            }
        }

        return dp[i][j] = res;  // Memoize result
    }

    //  3. Tabulation (Bottom-up DP)
    int solveTabulation(string &s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));

        // Single character requires 1 turn to print
        for (int i = 0; i < n; i++) dp[i][i] = 1;

        // Fill table from shorter substrings to longer ones
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i + 1; j < n; ++j) {
                // Start with worst case: print s[i] separately
                dp[i][j] = dp[i + 1][j] + 1;

                // Try to optimize by merging print with future matching characters
                for (int k = i + 1; k <= j; ++k) {
                    if (s[k] == s[i]) {
                        // Split into left and right subproblems
                        int left = (k - 1 >= i + 1) ? dp[i][k - 1] : 0;
                        int right = (k + 1 <= j) ? dp[k + 1][j] : 0;
                        dp[i][j] = min(dp[i][j], left + right);
                    }
                }
            }
        }

        return dp[0][n - 1]; // Final answer for s[0..n-1]
    }

    int strangePrinter(string s) {
        int n = s.size();

        // recursive version (will TLE for long strings)
        // return solveRecursive(s, 0, n - 1);

        // Memoization version
        vector<vector<int>> dp(n, vector<int>(n, -1));
        int memoAns = solveMemo(s, 0, n - 1, dp);

        // Tabulation version
        int tabAns = solveTabulation(s);

        // Optional: Print both to validate consistency
        cout << "Memoization Answer: " << memoAns << endl;
        cout << "Tabulation Answer: " << tabAns << endl;

        return tabAns; // Final result
    }
};

//https://leetcode.com/problems/perfect-squares/description/
//279. Perfect Squares
#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    // ---------- 1. Recursive Approach ----------
    // Time: Exponential O(2^n), Space: O(n) (Recursion stack)
    int solveRecursive(int n) {
        if (n == 0) return 0;

        int count = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            count = min(count, 1 + solveRecursive(n - square));
        }
        return count;
    }

    // ---------- 2. Memoization ----------
    // Time: O(n * sqrt(n)), Space: O(n) (DP + recursion stack)
    int solveMemo(int n, vector<int> &dp) {
        if (n == 0) return 0;
        if (dp[n] != -1) return dp[n];

        int count = INT_MAX;
        for (int i = 1; i * i <= n; i++) {
            int square = i * i;
            count = min(count, 1 + solveMemo(n - square, dp));
        }
        return dp[n] = count;
    }

    // ---------- 3. Tabulation (Bottom-Up DP) ----------
    // Time: O(n * sqrt(n)), Space: O(n)
    int solveTab(int n) {
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j * j <= i; j++) {
                int square = j * j;
                dp[i] = min(dp[i], 1 + dp[i - square]);
            }
        }

        return dp[n];
    }

    // ---------- Wrapper Function ----------
    int numSquares(int n) {
        // Uncomment one of the approaches below:

        // return solveRecursive(n);   // Very slow for large n (TLE)
        
        // vector<int> dp(n + 1, -1);
        // return solveMemo(n, dp);    // Efficient with memoization
        
        return solveTab(n);            // Most efficient (Bottom-Up DP)
    }
};

int main() {
    Solution sol;
    int n = 12;

    cout << "Minimum perfect squares needed for " << n << " = " << sol.numSquares(n) << endl;
    return 0;
}

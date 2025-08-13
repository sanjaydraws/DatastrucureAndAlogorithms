// 62. Unique Paths
// https://leetcode.com/problems/unique-paths/description/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    //  1. Recursive (TLE for large inputs)
    // T.C: O(2^(m+n)), S.C: O(m + n) recursion stack
    int recursive(int i, int j, int m, int n) {
        if (i >= m || j >= n) return 0;            // Out of bounds
        if (i == m - 1 && j == n - 1) return 1;     // Reached bottom-right
        return recursive(i + 1, j, m, n) + recursive(i, j + 1, m, n);
    }

    //  2. Memoization
    // T.C: O(m*n), S.C: O(m*n) for dp + recursion stack
    int memo(int i, int j, int m, int n, vector<vector<int>>& dp) {
        if (i >= m || j >= n) return 0;
        if (i == m - 1 && j == n - 1) return 1;
        if (dp[i][j] != -1) return dp[i][j];

        return dp[i][j] = memo(i + 1, j, m, n, dp) + memo(i, j + 1, m, n, dp);
    }

    //  3. Tabulation (Bottom-Up)
    // T.C: O(m*n), S.C: O(m*n)
    int tabulation(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];  // from top + left
            }
        }
        return dp[m - 1][n - 1];
    }

    //  4. Space Optimized (1D DP)
    // T.C: O(m*n), S.C: O(n)
    int spaceOptimized(int m, int n) {
        vector<int> dp(n, 1);  // 1st row is all 1s

        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[j] += dp[j - 1];  // current = top + left
            }
        }
        return dp[n - 1];
    }

    //  Wrapper to test all
    void testAll(int m, int n) {
        cout << "\n✅ Grid: " << m << " x " << n << "\n";

        // Recursive
        cout << "1. Recursive (T.C: O(2^(m+n))): ";
        cout << recursive(0, 0, m, n) << endl;

        // Memoization
        vector<vector<int>> dp(m, vector<int>(n, -1));
        cout << "2. Memoization (T.C: O(m*n)): ";
        cout << memo(0, 0, m, n, dp) << endl;

        // Tabulation
        cout << "3. Tabulation (T.C: O(m*n)): ";
        cout << tabulation(m, n) << endl;

        // Space Optimized
        cout << "4. Space Optimized (T.C: O(m*n), S.C: O(n)): ";
        cout << spaceOptimized(m, n) << endl;
    }
};

int main() {
    Solution obj;

    // Test with 2x2 grid
    obj.testAll(2, 2);

    // You can test other values:
    // obj.testAll(3, 3);
    // obj.testAll(10, 10);
    return 0;
}

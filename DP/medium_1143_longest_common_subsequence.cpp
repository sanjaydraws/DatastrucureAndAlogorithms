//https://leetcode.com/problems/longest-common-subsequence/description/
//1143. Longest Common Subsequence

#include <iostream>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

// 1️. Recursive Solution (Brute Force)
// T.C: O(2^n), S.C: O(n + m) (call stack)
int lcsRecursive(string& s1, string& s2, int i, int j) {
    if (i == s1.length() || j == s2.length()) return 0;

    if (s1[i] == s2[j])
        return 1 + lcsRecursive(s1, s2, i + 1, j + 1);
    else
        return max(lcsRecursive(s1, s2, i + 1, j), lcsRecursive(s1, s2, i, j + 1));
}

// 2️. Memoization (Top-down DP)
// T.C: O(n*m), S.C: O(n*m) + recursion stack
int lcsMemo(string& s1, string& s2, int i, int j, vector<vector<int>>& dp) {
    if (i == s1.length() || j == s2.length()) return 0;
    if (dp[i][j] != -1) return dp[i][j];

    if (s1[i] == s2[j])
        return dp[i][j] = 1 + lcsMemo(s1, s2, i + 1, j + 1, dp);
    else
        return dp[i][j] = max(lcsMemo(s1, s2, i + 1, j, dp), lcsMemo(s1, s2, i, j + 1, dp));
}

// 3️. Tabulation (Bottom-up DP)
// T.C: O(n*m), S.C: O(n*m)
int lcsTabulation(string& s1, string& s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
        }
    }
    return dp[0][0];
}

// 4️. Space Optimization (2 rows)
// T.C: O(n*m), S.C: O(m)
int lcsSpaceOptimized(string& s1, string& s2) {
    int n = s1.length(), m = s2.length();
    vector<int> next(m + 1, 0), curr(m + 1, 0);

    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j])
                curr[j] = 1 + next[j + 1];
            else
                curr[j] = max(next[j], curr[j + 1]);
        }
        next = curr;
    }
    return next[0];
}


int main() {
    string s1 = "abcde";
    string s2 = "ace";

    cout << "Recursive LCS: " << lcsRecursive(s1, s2, 0, 0) << endl;

    vector<vector<int>> dp(s1.length(), vector<int>(s2.length(), -1));
    cout << "Memoized LCS: " << lcsMemo(s1, s2, 0, 0, dp) << endl;

    cout << "Tabulated LCS: " << lcsTabulation(s1, s2) << endl;

    cout << "Space Optimized LCS: " << lcsSpaceOptimized(s1, s2) << endl;

    return 0;
}

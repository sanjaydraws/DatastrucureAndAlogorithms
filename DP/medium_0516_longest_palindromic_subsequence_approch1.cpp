// 516. Longest Palindromic Subsequence
// https://leetcode.com/problems/longest-palindromic-subsequence/

class Solution {
public:

    // 🔹 Method 1: Tabulation (2D DP)
    // T.C: O(n^2)  → for nested loops
    // S.C: O(n^2)  → full 2D dp table used
    int longestPalindromeSubseq(string s) {
        int n = s.length();
        
        // dp[i][j] stores the length of LPS in substring s[i...j]
        vector<vector<int>> dp(n, vector<int>(n, 0));
        
        // Base case: single characters are palindromes of length 1
        for (int i = 0; i < n; i++) {
            dp[i][i] = 1;
        }
        
        // Fill the table for substrings of length 2 to n
        for (int len = 2; len <= n; len++) {
            for (int i = 0; i <= n - len; i++) {
                int j = i + len - 1;  // Ending index of current substring
                
                if (s[i] == s[j]) {
                    // Characters match → take 2 + LPS of inner substring
                    // Handle edge case: if i+1 > j-1, then it's empty inside → take 0
                    dp[i][j] = 2 + dp[i + 1][j - 1];
                } else {
                    // Characters don't match → take max by skipping either end
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
                }
            }
        }

        // Final result is for the full string from index 0 to n-1
        return dp[0][n - 1];
    }

    // 🔹 Method 2: Space Optimized (1D DP)
    // T.C: O(n^2)  → same nested loops
    // S.C: O(n)    → only 2 arrays used: prev and curr
    int longestPalindromeSubseq2(string s) {
        int n = s.length();

        // prev[j] = dp[i+1][j], curr[j] = dp[i][j]
        vector<int> prev(n, 0), curr(n, 0);

        // Process from bottom to top (i from n-1 → 0)
        for (int i = n - 1; i >= 0; i--) {
            curr[i] = 1;  // Base case: single character → length 1

            // j goes from i+1 to n-1 → right of current i
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    // Match: Add 2 to inner LPS (prev[j - 1])
                    curr[j] = 2 + prev[j - 1];
                } else {
                    //prev[j] = value from next row (↓ down), i.e., dp[i+1][j]
                    // curr[j-1] = value from current row (← left), i.e., dp[i][j-1]
                    // Mismatch: Take max of skipping i or j
                    curr[j] = max(prev[j], curr[j - 1]);
                }
            }

            // Move current row to previous for next iteration
            prev = curr;
        }

        // Final result is stored in prev[n-1]
        return prev[n - 1];
    }

    // 🔹 Method 3: LCS Tabulation from Bottom-Right to Top-Left
    // T.C: O(n^2) → Nested loops for each cell
    // S.C: O(n^2) → Full 2D DP table
    int longestPalindromeSubseq4(string s) {
    string rev = s;
    reverse(rev.begin(), rev.end());
    return lcsTabulation(s, rev);
}

    //  Helper for Method 3
    int lcsTabulation(string& s1, string& s2) {
    int n = s1.length(), m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    // Fill from bottom-right (i=n-1,j=m-1) to top-left (i=0,j=0)
    for (int i = n - 1; i >= 0; i--) {
        for (int j = m - 1; j >= 0; j--) {
            if (s1[i] == s2[j])
                dp[i][j] = 1 + dp[i + 1][j + 1];  // Diagonal ↘ match
            else
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);  // Down ↓ or Right →
        }
    }

    return dp[0][0];  // LCS of s1 and s2 = longest palindromic subsequence
}

};

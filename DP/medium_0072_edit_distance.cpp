// 72. Edit Distance
//https://leetcode.com/problems/edit-distance/description/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    // 🔁 Tabulation Approach (2D DP)
    // TC: O(n * m), SC: O(n * m)
    int minDistanceTab(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // dp[i][j] = min operations to convert word1[0..i-1] to word2[0..j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1));

        // Base case: empty strings
        for (int i = 0; i <= n; i++) dp[i][0] = i;  // delete all
        for (int j = 0; j <= m; j++) dp[0][j] = j;  // insert all

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1];  // same char → no op
                } else {
                    dp[i][j] = 1 + min({
                        dp[i - 1][j],    // delete from word1
                        dp[i][j - 1],    // insert into word1
                        dp[i - 1][j - 1] // replace in word1
                    });
                }
            }
        }

        return dp[n][m];
    }

    // 🔁 Space Optimized DP (1D Arrays)
    // TC: O(n * m), SC: O(m)
    int minDistanceSpaceOptimized(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<int> prev(m + 1), curr(m + 1);

        // Base case: convert "" to word2 (insert all chars)
        for (int j = 0; j <= m; j++) {
            prev[j] = j;
        }

        for (int i = 1; i <= n; i++) {
            curr[0] = i;  // delete all chars to make word1[0..i-1] → ""
            for (int j = 1; j <= m; j++) {
                if (word1[i - 1] == word2[j - 1]) {
                    curr[j] = prev[j - 1];  // same char → no op
                } else {
                    curr[j] = 1 + min({
                        prev[j],     // delete
                        curr[j - 1], // insert
                        prev[j - 1]  // replace
                    });
                }
            }
            prev = curr;  // update row
        }

        return prev[m];
    }
};

//1143. Longest Common Subsequence
// https://leetcode.com/problems/longest-common-subsequence/description/


//Approach : Brute Force
class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        return solve(s1,s2, 0, 0);
    }
    int solve(string& s1, string& s2,int i, int j){
        if(i == s1.length() || j == s2.length()) return 0;
        if(s1[i] == s2[j]){
            return 1 + solve(s1, s2 , i + 1, j + 1);
        }else{
            return max(solve(s1, s2 , i + 1, j), solve(s1, s2 , i, j + 1));
        }
    }
};

//Approach 2 : Memoization Code
//Time: O(m * n) (har state max ek hi bar calculate hota hai).

//Space: O(m * n) for dp + O(m+n) recursion stack.
//
class Solution2 {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();
        // dp[i][j] = LCS of s1[i..end], s2[j..end]
        vector<vector<int>> dp(m, vector<int>(n, -1));
        return solve(s1, s2, 0, 0, dp);
    }

    int solve(string &s1, string &s2, int i, int j, vector<vector<int>> &dp) {
        // base case
        if(i == s1.length() || j == s2.length()) return 0;

        // already calculated
        if(dp[i][j] != -1) return dp[i][j];

        // case 1: characters match
        if(s1[i] == s2[j]) {
            dp[i][j] = 1 + solve(s1, s2, i+1, j+1, dp);
        } 
        // case 2: characters don’t match
        else {
            dp[i][j] = max(
                solve(s1, s2, i+1, j, dp),
                solve(s1, s2, i, j+1, dp)
            );
        }

        return dp[i][j];
    }
};
// Approach 3 : tabulization

class Solution {
public:
    int longestCommonSubsequence(string s1, string s2) {
        int m = s1.length();
        int n = s2.length();

        // dp[i][j] = LCS length of substring s1[i..end] and s2[j..end]
        vector<vector<int>> dp(m+1, vector<int>(n+1, 0));

        // Bottom-up filling
        // Traverse from end of strings towards the beginning
        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {
                if (s1[i] == s2[j]) {
                    // Characters match → take 1 + diagonal value
                    dp[i][j] = 1 + dp[i+1][j+1];
                } else {
                    // Characters don't match → take max of (skip s1[i], skip s2[j])
                    dp[i][j] = max(dp[i+1][j], dp[i][j+1]);
                }
            }
        }

        // Final answer = LCS of full strings → dp[0][0]
        return dp[0][0];
    }
};


// Approach 4 : space optimization
//Time: O(n*m)

// Space: O(m) only

int longestCommonSubsequence(string text1, string text2) {
    int n = text1.size(), m = text2.size();
    
    vector<int> prev(m+1, 0), curr(m+1, 0);

    for (int i = n-1; i >= 0; i--) {
        for (int j = m-1; j >= 0; j--) {
            if (text1[i] == text2[j]) {
                curr[j] = 1 + prev[j+1]; // match → take diagonal
            } else {
                curr[j] = max(prev[j], curr[j+1]); // mismatch → max(down, right) // down from prev andd right from curr 
            }
        }
        prev = curr; // move current row → prev row
    }
    
    return prev[0];
}

// 🔗 https://leetcode.com/problems/burst-balloons/
// ✅ 312. Burst Balloons

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Approach 1: Interval DP - Bottom-Up Tabulation
    // ⏱ Time: O(n^3),  Space: O(n^2)
    int maxCoinsTabulation(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Add 1 at both ends → arr = [1, nums..., 1]
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        // Step 2: Create DP table
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Step 3: Fill DP table from shorter intervals to longer
        for (int len = 2; len <= n + 1; len++) {
            for (int left = 0; left <= n + 1 - len; left++) {
                int right = left + len;

                // Try each k as the last balloon to burst in (left, right)
                for (int k = left + 1; k < right; k++) {
                    int coins = arr[left] * arr[k] * arr[right];
                    dp[left][right] = max(dp[left][right],
                                          dp[left][k] + coins + dp[k][right]);
                }
            }
        }

        // Final result: burst everything between index 0 and n+1
        return dp[0][n + 1];
    }

    //  Approach 2: Interval DP - Top-Down Memoization
    //  Time: O(n^3),  Space: O(n^2) + recursion stack
    int maxCoinsMemoization(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Add 1 at both ends
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        // Step 2: Initialize DP memo table with -1
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, -1));

        // Step 3: Call recursive function
        return solve(0, n + 1, arr, dp);
    }

private:
    // Helper function for memoization
    int solve(int i, int j, vector<int>& arr, vector<vector<int>>& dp) {
        // Base case: no balloons between
        if (i + 1 == j) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        int maxCoins = 0;

        // Try bursting each balloon in between
        for (int k = i + 1; k < j; k++) {
            int coins = arr[i] * arr[k] * arr[j];
            coins += solve(i, k, arr, dp);
            coins += solve(k, j, arr, dp);
            maxCoins = max(maxCoins, coins);
        }

        return dp[i][j] = maxCoins;
    }
};

//  Main function to test both
int main() {
    vector<int> nums = {3, 1, 5, 8};
    Solution sol;

    int result1 = sol.maxCoinsTabulation(nums);
    cout << "Maximum coins (Tabulation): " << result1 << endl;  // Output: 167

    int result2 = sol.maxCoinsMemoization(nums);
    cout << "Maximum coins (Memoization): " << result2 << endl;  // Output: 167

    return 0;
}

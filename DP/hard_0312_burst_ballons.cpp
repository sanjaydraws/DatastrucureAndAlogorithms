//https://leetcode.com/problems/burst-balloons/description/
// 312. Burst Balloons

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();

        // Step 1: Pad the nums with 1 at both ends
        // Example: nums = [3,1,5] → arr = [1,3,1,5,1]
        vector<int> arr(n + 2, 1);
        for (int i = 0; i < n; i++) {
            arr[i + 1] = nums[i];
        }

        // Step 2: Initialize a 2D DP table
        // dp[i][j] = max coins from bursting balloons between i and j (exclusive)
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // Step 3: Fill DP table by increasing interval lengths
        // len = size of the current window
        for (int len = 2; len <= n + 1; len++) {
            for (int left = 0; left <= n + 1 - len; left++) {
                int right = left + len;

                // Try every balloon k between left and right as the last to burst
                for (int k = left + 1; k < right; k++) {
                    int coins = arr[left] * arr[k] * arr[right];  // Coins from bursting k last
                    dp[left][right] = max(dp[left][right],
                                          dp[left][k] + coins + dp[k][right]);
                }
            }
        }

        // Final result is bursting all balloons between index 0 and n+1
        return dp[0][n + 1];
    }
};

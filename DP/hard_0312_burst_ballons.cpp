//  https://leetcode.com/problems/burst-balloons/
//  312. Burst Balloons

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
   //  Approach: Interval DP
   // ⏱️ Time Complexity: O(n^3)
   // 💾 Space Complexity: O(n^2)

    int maxCoins(vector<int>& nums) {
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
};

int main() {
    vector<int> nums = {3, 1, 5, 8};
    Solution sol;
    int result = sol.maxCoins(nums);
    cout << "Maximum coins collected: " << result << endl;  // Output: 167
    return 0;
}

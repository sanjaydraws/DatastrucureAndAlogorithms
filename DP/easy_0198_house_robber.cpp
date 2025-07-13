//198. House Robber
//https://leetcode.com/problems/house-robber/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    // Memoization (Top-down DP) - O(n) Time, O(n) Space
    int robMemo(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, -1);
        return helper(0, nums, dp);
    }

    int helper(int i, vector<int>& nums, vector<int>& dp) {
        if (i >= nums.size()) return 0;
        if (dp[i] != -1) return dp[i];
        int rob = nums[i] + helper(i + 2, nums, dp);
        int skip = helper(i + 1, nums, dp);
        return dp[i] = max(rob, skip);
    }

    // Tabulation (Bottom-up DP) - O(n) Time, O(n) Space
    int robTab(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        vector<int> dp(n);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            dp[i] = max(nums[i] + dp[i - 2], dp[i - 1]);
        }
        return dp[n - 1];
    }

    // Space Optimized - O(n) Time, O(1) Space
    int robSpaceOptimized(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        if (n == 1) return nums[0];

        int prev2 = nums[0];
        int prev1 = max(nums[0], nums[1]);

        for (int i = 2; i < n; i++) {
            int curr = max(nums[i] + prev2, prev1);
            prev2 = prev1;
            prev1 = curr;
        }
        return prev1;
    }
};

int main() {
    vector<int> nums = {2, 7, 9, 3, 1};
    Solution sol;

    cout << "Memoization: " << sol.robMemo(nums) << endl;
    cout << "Tabulation: " << sol.robTab(nums) << endl;
    cout << "Space Optimized: " << sol.robSpaceOptimized(nums) << endl;

    return 0;
}
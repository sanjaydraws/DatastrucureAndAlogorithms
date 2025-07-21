//55. Jump Game
//https://leetcode.com/problems/jump-game/description/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
--------------------------------------------------------
1️ RECURSIVE BACKTRACKING (TLE for large inputs)
Time Complexity: O(2^n)
Space Complexity: O(n) → recursion stack
--------------------------------------------------------
*/
bool canJumpRecursive(int i, vector<int>& nums) {
    if (i >= nums.size() - 1) return true;

    for (int j = 1; j <= nums[i]; j++) {
        if (canJumpRecursive(i + j, nums)) return true;
    }

    return false;
}

/*
--------------------------------------------------------
2️ TOP-DOWN DYNAMIC PROGRAMMING (Memoization)
Time Complexity: O(n^2)
Space Complexity: O(n) for dp[] + O(n) recursion stack
--------------------------------------------------------
*/
bool canJumpMemo(int i, vector<int>& nums, vector<int>& dp) {
    if (i >= nums.size() - 1) return true;
    if (dp[i] != -1) return dp[i];

    for (int j = 1; j <= nums[i]; j++) {
        if (canJumpMemo(i + j, nums, dp)) return dp[i] = 1;
    }

    return dp[i] = 0;
}

/*
--------------------------------------------------------
3️ BOTTOM-UP DYNAMIC PROGRAMMING (Tabulation)
Time Complexity: O(n^2)
Space Complexity: O(n)
--------------------------------------------------------
*/
bool canJumpTabulation(vector<int>& nums) {
    int n = nums.size();
    vector<bool> dp(n, false);

    // Last index is always reachable from itself
    dp[n - 1] = true;

    // Iterate from second last index to 0
    for (int i = n - 2; i >= 0; i--) {
        // Check if any jump from i can reach a true dp
        for (int j = 1; j <= nums[i] && i + j < n; j++) {
            if (dp[i + j]) {
                dp[i] = true;
                break;
            }
        }
    }

    return dp[0];
}

/*
--------------------------------------------------------
4️ GREEDY APPROACH (Best and Most Optimal)
Time Complexity: O(n)
Space Complexity: O(1)
--------------------------------------------------------
*/
bool canJumpGreedy(vector<int>& nums) {
    int maxReach = 0;

    for (int i = 0; i < nums.size(); i++) {
        if (i > maxReach) return false; // Cannot proceed further
        maxReach = max(maxReach, i + nums[i]);
    }

    return true;
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4}; // Sample input
    int n = nums.size();

    cout << "Input: ";
    for (int num : nums) cout << num << " ";
    cout << "\n\n";

    // 1️ Recursive Approach
    cout << "Recursive Backtracking:       ";
    cout << (canJumpRecursive(0, nums) ? "true" : "false") << "\n";

    // 2️ Memoization
    vector<int> dp(n, -1);
    cout << "Top-Down Memoization (DP):    ";
    cout << (canJumpMemo(0, nums, dp) ? "true" : "false") << "\n";

    // 3️ Bottom-Up Tabulation
    cout << "Bottom-Up Tabulation (DP):    ";
    cout << (canJumpTabulation(nums) ? "true" : "false") << "\n";

    // 4️ Greedy Approach
    cout << "Greedy (Most Optimal):        ";
    cout << (canJumpGreedy(nums) ? "true" : "false") << "\n";

    return 0;
}

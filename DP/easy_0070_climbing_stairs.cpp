
// https://leetcode.com/problems/climbing-stairs/description/
// 70. Climbing Stairs
#include <iostream>
#include <vector>
using namespace std;

//  1. Pure Recursion (Exponential Time)
int climbStairsRecursive(int n) {
    if (n <= 2) return n;
    return climbStairsRecursive(n - 1) + climbStairsRecursive(n - 2);
}

//  2. Memoization (Top-Down DP)
int climbStairsMemoHelper(int n, vector<int>& dp) {
    if (n <= 2) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = climbStairsMemoHelper(n - 1, dp) + climbStairsMemoHelper(n - 2, dp);
}

int climbStairsMemo(int n) {
    vector<int> dp(n + 1, -1);
    return climbStairsMemoHelper(n, dp);
}

//  3. Tabulation (Bottom-Up DP)
int climbStairsTabulation(int n) {
    if (n <= 2) return n;
    vector<int> dp(n + 1);
    dp[0] = 1;  // 1 way to stay at ground
    dp[1] = 1;  // 1 way to reach step 1

    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// 4. Space Optimized DP
int climbStairsOptimized(int n) {
    if (n <= 2) return n;

    int prev2 = 1, prev1 = 2;
    for (int i = 3; i <= n; i++) {
        int curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

int main() {
    int n = 6;

    cout << "Climbing Stairs Problem for n = " << n << endl;
    cout << "1. Pure Recursion: " << climbStairsRecursive(n) << endl;
    cout << "2. Memoization (Top-Down): " << climbStairsMemo(n) << endl;
    cout << "3. Tabulation (Bottom-Up): " << climbStairsTabulation(n) << endl;
    cout << "4. Space Optimized: " << climbStairsOptimized(n) << endl;

    return 0;
}



/**
 * 
 * 
 * Time & Space Complexity Summary:
Method	               Time	   Space
Pure Recursion    	O(2^n)	O(n) stack
Memoization	         O(n)	O(n)
Tabulation	        O(n)	O(n)
Space Optimized  	O(n)	O(1) ✅
 */
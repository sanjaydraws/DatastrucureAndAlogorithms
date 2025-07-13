#include <iostream>
#include <vector>
using namespace std;

// 1. Brute-force Recursion
int fibBrute(int n) {
    if (n <= 1) return n;
    return fibBrute(n - 1) + fibBrute(n - 2);
}
// Time Complexity: O(2^n), Space Complexity: O(n) recursion stack

// 2. Memoization (Top-down Dynamic Programming)
int fibMemo(int n, vector<int>& dp) {
    if (n <= 1) return n;
    if (dp[n] != -1) return dp[n];
    return dp[n] = fibMemo(n - 1, dp) + fibMemo(n - 2, dp);
}
// Time Complexity: O(n), Space Complexity: O(n) for dp + O(n) recursion stack

// 3. Tabulation (Bottom-up Dynamic Programming)
int fibTab(int n) {
    if (n <= 1) return n;
    vector<int> dp(n + 1);
    dp[0] = 0; dp[1] = 1;
    for (int i = 2; i <= n; ++i)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
// Time Complexity: O(n), Space Complexity: O(n)

// 4. Space Optimized Dynamic Programming
int fibOptimized(int n) {
    if (n <= 1) return n;
    int prev2 = 0, prev1 = 1, curr;
    for (int i = 2; i <= n; ++i) {
        curr = prev1 + prev2;
        prev2 = prev1;
        prev1 = curr;
    }
    return curr;
}
// Time Complexity: O(n), Space Complexity: O(1)

int main() {
    int n = 10;

    cout << "Fibonacci number for n = " << n << " using different methods:\n\n";

    cout << "1. Brute-force Recursion: " << fibBrute(n) << "\n";
    cout << "   Time Complexity: O(2^n), Space Complexity: O(n)\n\n";

    vector<int> dp(n + 1, -1);
    cout << "2. Memoization (Top-down DP): " << fibMemo(n, dp) << "\n";
    cout << "   Time Complexity: O(n), Space Complexity: O(n)\n\n";

    cout << "3. Tabulation (Bottom-up DP): " << fibTab(n) << "\n";
    cout << "   Time Complexity: O(n), Space Complexity: O(n)\n\n";

    cout << "4. Space Optimized DP: " << fibOptimized(n) << "\n";
    cout << "   Time Complexity: O(n), Space Complexity: O(1)\n";

    return 0;
}

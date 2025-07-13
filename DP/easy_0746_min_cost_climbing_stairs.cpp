//https://leetcode.com/problems/min-cost-climbing-stairs/description/
//746. Min Cost Climbing Stairs

#include <iostream>
#include <vector>
using namespace std;

// ✅ Tabulation (Bottom-Up DP)
int minCostClimbingStairsTabulation(vector<int>& cost) {
    int n = cost.size();

    if (n == 0) return 0;
    if (n == 1) return cost[0];

    vector<int> dp(n);
    dp[0] = cost[0];
    dp[1] = cost[1];

    for (int i = 2; i < n; i++) {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

// ✅ Space Optimized DP
int minCostClimbingStairsOptimized(vector<int>& cost) {
    int n = cost.size();

    if (n == 0) return 0;
    if (n == 1) return cost[0];

    int prev2 = cost[0];
    int prev1 = cost[1];

    for (int i = 2; i < n; i++) {
        int curr = cost[i] + min(prev1, prev2);
        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int main() {
    vector<int> cost = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};

    int resultTab = minCostClimbingStairsTabulation(cost);
    int resultOpt = minCostClimbingStairsOptimized(cost);

    cout << "Minimum cost to reach the top (Tabulation): " << resultTab << endl;
    cout << "Minimum cost to reach the top (Optimized): " << resultOpt << endl;

    return 0;
}
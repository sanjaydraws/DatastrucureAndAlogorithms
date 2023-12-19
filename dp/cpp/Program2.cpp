
//https://leetcode.com/problems/min-cost-climbing-stairs/
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int solve(vector<int>&cost, int n){
        // base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        int ans = cost[n] + min(solve(cost, n-1),solve(cost, n-2));
        return ans;
    }
    //memoization (T.C - O(N), S.C => O(N) + O(N))
    int solve2(vector<int>& cost, int n,vector<int>& dp){
        //base case
        if(n == 0){
            return cost[0];
        }
        if(n == 1){
            return cost[1];
        }
        // step 3:
        if(dp[n] != -1){
            return dp[n];
        }
        //step 2:
        dp[n] = cost[n] + min(solve2(cost, n-1, dp),solve2(cost, n-2, dp));
        return dp[n];
    }
    //tabulation // bottomup approach
    // (T.C - O(N), S.C => O(N)
    int solve3(vector<int>& cost, int n ){
        //step1
        vector<int> dp(n+1);
        // step 2 base case
        dp[0] = cost[0];
        dp[1] = cost[1];
        // 3rd step
        for(int i = 2; i<n; i++){
            dp[i] = cost[i] + min(dp[i -1],dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    // space optimization
        // (T.C - O(N), S.C => O(1)
    int solve4(vector<int>& cost, int n ){
        int prev2 = cost[0];
        int prev1 = cost[1];
        // 3rd step
        for(int i = 2; i<n; i++){
            int curr = cost[i] + min(prev1, prev2);
            // dp[i] = cost[i] + min(dp[i -1],dp[i-2]);// replaced this 
            prev2 = prev1;
            prev1 = curr;
        }
        return min(prev1, prev2);
    }
    int minCostClimbingStairs(vector<int>& cost) {

        //Recursion
        // int n = cost.size();
        // int ans = min(solve(cost,n-1),solve(cost,n-2));
        // return ans;


        //Memoization
        // step 1
        int n  = cost.size();
        vector<int> dp(n+1, -1);
        int ans = min(solve2(cost, n-1,dp),solve2(cost,n-2,dp));
        return ans;

        //Bottomup tabulation //tabulation
        // int n = cost.size();
        // return solve3(cost, n);


        // space optimization
        int n = cost.size();
        return solve4(cost, n );

    }
};

int main() {
    Solution solution;
    std::vector<int> cost = {10, 15, 20};
    int result = solution.minCostClimbingStairs(cost);
    cout << "Output: " << result << std::endl;

    return 0;
}

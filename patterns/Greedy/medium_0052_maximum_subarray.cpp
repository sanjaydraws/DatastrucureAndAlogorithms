// 53. Maximum Subarray
//https://leetcode.com/problems/maximum-subarray/description/

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Find the maximum sum of a contiguous subarray.
 Approach: Kadane's Algorithm — Greedy + DP

 Time Complexity: O(n) — One pass through the array
 Space Complexity: O(1) — Constant extra space

Kadane’s is Greedy + DP:
Har index pe greedy decision: start new or continue?

Implicit DP: result of subproblem i depends on i-1.
 */

int maxSubArray(vector<int>& nums) {
    int max_sum = INT_MIN;  // Stores the maximum sum found so far
    int curr_sum = 0;       // Stores current subarray sum

    for (int num : nums) {
        // Decide: extend previous subarray or start new from current element
        curr_sum = max(num, curr_sum + num);

        // Update overall maximum if current subarray is better
        max_sum = max(max_sum, curr_sum);
    }

    return max_sum;
}

int main() {
    vector<int> nums = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    cout << "Maximum Subarray Sum = " << maxSubArray(nums) << endl;
    return 0;
}

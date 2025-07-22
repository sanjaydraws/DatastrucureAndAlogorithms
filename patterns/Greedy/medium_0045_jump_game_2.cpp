// https://leetcode.com/problems/jump-game-ii/submissions/1706335914/
// 45. Jump Game II

#include <bits/stdc++.h>
using namespace std;

/*
     Greedy Approach (Optimal)
    ----------------------------
    Idea:
    - At each index, update the farthest position we can reach.
    - When we reach the end of current jump range, we make a jump and reset the range.

    Dry Run for nums = [2,3,1,1,4]
    ------------------------------------------------
    i = 0 → farthest = max(0, 0+2) = 2
           → i == end → jump++, end = farthest = 2

    i = 1 → farthest = max(2, 1+3) = 4
    i = 2 → farthest = max(4, 2+1) = 4
           → i == end → jump++, end = farthest = 4

    Done. We reached last index in 2 jumps.

    Time Complexity: O(N)
    Space Complexity: O(1)
*/
int jumpGreedy(vector<int>& nums) {
    int jumps = 0, end = 0, farthest = 0;

    for (int i = 0; i < nums.size() - 1; ++i) {
        farthest = max(farthest, i + nums[i]); // update max reach

        if (i == end) { // current jump ends here
            jumps++;        // make a jump
            end = farthest; // move end to the farthest
        }
    }

    return jumps;
}

/*
     Dynamic Programming Approach (Slower)
    ---------------------------------------
    dp[i] = Minimum number of jumps to reach index i

    For each index i, try jumping from i to j in range [i+1, i + nums[i]]
    and update dp[j] = min(dp[j], dp[i] + 1)

    Time Complexity: O(N^2)
    Space Complexity: O(N)
*/
int jumpDP(vector<int>& nums) {
    int n = nums.size();
    vector<int> dp(n, INT_MAX);
    dp[0] = 0; // base case: 0 jumps to reach 0

    for (int i = 0; i < n; ++i) {
        // Try all jumps from i
        for (int j = i + 1; j <= i + nums[i] && j < n; ++j) {
            dp[j] = min(dp[j], dp[i] + 1);
        }
    }

    return dp[n - 1]; // min jumps to reach last index
}

int main() {
    vector<int> nums = {2, 3, 1, 1, 4};

    cout << "Input: ";
    for (int x : nums) cout << x << " ";
    cout << "\n\n";

    cout << "Greedy Approach → Minimum Jumps: " << jumpGreedy(nums) << endl;
    cout << " DP Approach     → Minimum Jumps: " << jumpDP(nums) << endl;

    return 0;
}

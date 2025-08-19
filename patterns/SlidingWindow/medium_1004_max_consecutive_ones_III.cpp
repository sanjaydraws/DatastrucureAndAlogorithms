//1004. Max Consecutive Ones III
//https://leetcode.com/problems/max-consecutive-ones-iii/description/

class Solution {
public:
    // Approach: Sliding Window (Variable Size Window)
    // We try to find the longest subarray with at most k zeros.
    // Expand the window by moving 'right'. 
    // If zeros exceed k, shrink window by moving 'left'.
    // Keep track of max window length.

    // Time Complexity: O(n)  -> Each element visited at most twice (right and left)
    // Space Complexity: O(1) -> Only a few extra variables

    int longestOnes(vector<int>& nums, int k) {
        int left = 0, ans  = 0, zeros = 0;

        // Expand window with 'right'
        for (int right = 0; right < nums.size(); right++) {
            if (nums[right] == 0) zeros++;  // count zeros in window

            // Shrink window if zeros > k
            while (zeros > k) {
                if (nums[left] == 0) zeros--;
                left++;
            }

            // Update maximum window length
            ans = max(ans, right - left + 1);
        }
        return ans;
    }
};

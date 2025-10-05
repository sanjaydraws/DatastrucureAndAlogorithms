// Prefix/Suffix Product / Space Optimized
//238. Product of Array Except Self


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Time Complexity: O(n)
    // Space Complexity: O(1) extra space (output array doesn't count)
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> output(n, 1);

        // Step 1: Compute left products
        for (int i = 1; i < n; i++) {
            output[i] = output[i-1] * nums[i-1];
        }

        // Step 2: Multiply with right products
        int R = 1; // suffix product
        for (int i = n-1; i >= 0; i--) {
            output[i] *= R;
            R *= nums[i];
        }

        return output;
    }
};

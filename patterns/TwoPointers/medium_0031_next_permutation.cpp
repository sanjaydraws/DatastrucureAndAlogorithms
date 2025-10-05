// 31. Next Permutation

//Two Pointers //Greedy / Math


/*
lexicographical permutation: the next permutation is the smallest possible arrangement 
that is greater than the current one.
Array: [1,2,3]
All permutations in order: 123, 132, 213, 231, 312, 321
Next permutation of [1,2,3] = [1,3,2]
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ---------------------------------------------------------
    // Goal: Rearrange nums into the next lexicographical permutation
    // Time Complexity: O(n) → single pass to find pivot + swap + reverse suffix
    // Space Complexity: O(1) → in-place, only pointers used
    // ---------------------------------------------------------
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i = n - 2;

        // Step 1: Find first decreasing element from the right (pivot)
        while (i >= 0 && nums[i] >= nums[i + 1]) {
            i--;
        }

        if (i >= 0) {
            // Step 2: Find first element from right just greater than nums[i]
            int j = n - 1;
            while (j >= 0 && nums[j] <= nums[i]) {
                j--;
            }
            // Step 3: Swap pivot (nums[i]) with nums[j]
            swap(nums[i], nums[j]);
        }

        // Step 4: Reverse the suffix (from i+1 to end) to get smallest lexicographic order
        reverse(nums.begin() + i + 1, nums.end());
    }
};

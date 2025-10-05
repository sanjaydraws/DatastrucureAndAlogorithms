// 75. sort colors
//https://leetcode.com/problems/sort-colors/description/


// Two Pointers | Sorting / Partitioning | Simulation / In-place algorithm(no extra memory taken)
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // ---------------------------------------------------------
    // Approach 1: Counting Sort (Two-pass)
    // ---------------------------------------------------------
    // Time Complexity: O(n) → one pass for counting, one pass for rewriting
    // Space Complexity: O(1) → only 3 counters used
    void sortColorsCounting(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;

        // Count the number of 0s, 1s, and 2s
        for (int n : nums) {
            if (n == 0) count0++;
            else if (n == 1) count1++;
            else count2++;
        }

        // Rewrite the array based on counts
        int i = 0;
        while (count0--) nums[i++] = 0;
        while (count1--) nums[i++] = 1;
        while (count2--) nums[i++] = 2;
    }

    // ---------------------------------------------------------
    // Approach 2: Dutch National Flag Algorithm (One-pass Optimal)
    // ---------------------------------------------------------
    // Time Complexity: O(n) → each element is processed at most once
    // Space Complexity: O(1) → only 3 pointers (low, mid, high)
    void sortColorsDutchFlag(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1;

        // Process elements until mid crosses high
        while (mid <= high) {
            if (nums[mid] == 0) {
                swap(nums[low], nums[mid]);
                low++, mid++;
            }
            else if (nums[mid] == 1) {
                mid++;
            }
            else { // nums[mid] == 2
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

int main() {
    Solution sol;

    vector<int> nums1 = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = {2, 0, 2, 1, 1, 0};

    cout << "Original Array: ";
    for (int n : nums1) cout << n << " ";
    cout << "\n";

    // Using Counting Sort
    sol.sortColorsCounting(nums1);
    cout << "Sorted (Counting Sort): ";
    for (int n : nums1) cout << n << " ";
    cout << "\n";

    // Using Dutch National Flag Algorithm
    sol.sortColorsDutchFlag(nums2);
    cout << "Sorted (Dutch National Flag): ";
    for (int n : nums2) cout << n << " ";
    cout << "\n";

    return 0;
}

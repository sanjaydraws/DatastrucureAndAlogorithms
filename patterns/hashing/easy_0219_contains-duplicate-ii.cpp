/**
LeetCode 219: Contains Duplicate II
 https://leetcode.com/problems/contains-duplicate-ii/description/
 Given an integer array nums and an integer k, return true if there are two distinct indices i and j in the array such that nums[i] == nums[j] and abs(i - j) <= k.

 

Example 1:

Input: nums = [1,2,3,1], k = 3
Output: true
Example 2:

Input: nums = [1,0,1,1], k = 1
Output: true
Example 3: 
**/

// Sliding Window with Hash Set
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check if any duplicate exists within distance k
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    unordered_set<int> window;

    for (int i = 0; i < nums.size(); i++) {
        // Maintain sliding window of size at most k
        if (i > k) {
            // Remove the element that is out of the window
            window.erase(nums[i - k - 1]);
        }

        // Check if current number already exists in the window
        if (window.count(nums[i])) {
            return true; // Found duplicate within k distance
        }

        // Add current number to the window
        window.insert(nums[i]);
    }

    return false; // No such pair found
}

int main() {
    vector<int> nums = {1, 2, 3, 1}; 
    int k = 3;

    bool result = containsNearbyDuplicate(nums, k);

    cout << (result ? "true" : "false") << endl; // true 

    return 0;
}

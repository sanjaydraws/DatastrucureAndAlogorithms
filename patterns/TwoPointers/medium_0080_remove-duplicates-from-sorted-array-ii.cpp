// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/description/

// 80. Remove Duplicates from Sorted Array II

/**
 * 
 * 
 * 
 * Example 1:

Input: nums = [1,1,1,2,2,3]
Output: 5, nums = [1,1,2,2,3,_]
Explanation: Your function should return k = 5, with the first five elements of nums being 1, 1, 2, 2 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
Example 2:

Input: nums = [0,0,1,1,1,1,2,3,3]
Output: 7, nums = [0,0,1,1,2,3,3,_,_]
Explanation: Your function should return k = 7, with the first seven elements of nums being 0, 0, 1, 1, 2, 3 and 3 respectively.
It does not matter what you leave beyond the returned k (hence they are underscores).
 */

 #include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates allowing at most two occurrences
int removeDuplicates(vector<int>& nums) {
    int j = 1;           // Pointer to place next valid element
    int count = 1;       // Count occurrences of current element

    for (int i = 1; i < nums.size(); i++) {
        // If current number is same as previous, increase count
        if (nums[i] == nums[i - 1]) {
            count += 1;
        } else {
            count = 1;   // New number found, reset count to 1
        }

        // If count is less than or equal to 2, keep it
        if (count <= 2) {
            nums[j] = nums[i]; // Overwrite at position j
            j++;               // Move pointer for next valid placement
        }
    }

    return j; // Final length of modified array
}

// Main function to test the logic
int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};

    // Call the function and store the new length
    int newLength = removeDuplicates(nums);

    // Print the new length
    cout << "New length: " << newLength << endl;

    // Print the modified array (first newLength elements only)
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

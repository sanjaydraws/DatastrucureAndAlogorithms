// 977. Squares of a Sorted Array
//Easy
//https://leetcode.com/problems/squares-of-a-sorted-array/description/

// Given an integer array nums sorted in non-decreasing order, return an array of the squares of each number sorted in non-decreasing order.

 /**
  * 
  * 
Example 1:
Input: nums = [-4,-1,0,3,10]
Output: [0,1,9,16,100]
Explanation: After squaring, the array becomes [16,1,0,9,100].
After sorting, it becomes [0,1,9,16,100].

Example 2:
Input: nums = [-7,-3,2,3,11]
Output: [4,9,9,49,121]
  */

#include <iostream>
#include <vector>
using namespace std;

vector<int> sortedSquares(vector<int>& nums) {
    int l = 0;                        // Left pointer starts at beginning
    int r = nums.size() - 1;         // Right pointer starts at end
    int n = nums.size();             // Total number of elements
    int pos = n - 1;                 // Position to fill in the result array (from end)

    vector<int> result(n);           // Result array to store sorted squares

    // Loop until the two pointers meet
    while (l <= r) {
        int lSquare = nums[l] * nums[l];   // Square of left element
        int rSquare = nums[r] * nums[r];   // Square of right element

        // Place the larger square at the current position from the end
        if (lSquare > rSquare) {
            result[pos] = lSquare;
            l++;                    // Move left pointer forward
        } else {
            result[pos] = rSquare;
            r--;                    // Move right pointer backward
        }

        pos--;                      // Move to the next position to fill
    }

    return result;                  // Return the fully sorted squares array
}


// Main function to test the code
int main() {
    vector<int> nums = {-7, -3, 2, 3, 11};

    vector<int> result = sortedSquares(nums);

    cout << "Sorted squares: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}

// Output
// Sorted squares: 4 9 9 49 121

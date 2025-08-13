


// https://leetcode.com/problems/remove-duplicates-from-sorted-array/
// 26. Remove Duplicates from Sorted Array


#include <iostream>
#include <vector>
using namespace std;

// Function to remove duplicates from sorted array
int removeDuplicates(vector<int>& nums) {
    // Edge case: if array is empty, return 0
    if (nums.empty()) return 0;

    int j = 1; // j points to the position where next unique element goes

    // Loop through array starting from index 1
    for (int i = 1; i < nums.size(); i++) {
        // If current element is different from the previous one
        if (nums[i] != nums[i - 1]) {
            nums[j] = nums[i]; // Place the unique element at index j
            j++;               // Move j to next position
        }
    }

    return j; // j is the count of unique elements
}

int main() {
    vector<int> nums = {1, 1, 2, 2, 3, 3, 4};

    int newLength = removeDuplicates(nums);

    cout << "New length: " << newLength << endl;

    cout << "Modified array with unique elements: ";
    for (int i = 0; i < newLength; i++) {
        cout << nums[i] << " ";
    }
    cout << endl;

    return 0;
}

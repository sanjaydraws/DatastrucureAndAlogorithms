//  LeetCode 217 : Contains Duplicate
// https://leetcode.com/problems/contains-duplicate/description/
// Space Complexity: O(n)//worst case, all n elements are unique set will store all n elements
// Time Complexity: O(n)

#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to check for duplicates
bool containsDuplicate(const vector<int>& nums) {
    unordered_set<int> seen;

    for (int num : nums) {
        if (seen.count(num)) {
            return true; // Duplicate found
        }
        seen.insert(num);
    }

    return false; // All elements are unique
}

int main() {
    vector<int> nums = {1, 2, 3, 1}; 

    if (containsDuplicate(nums)) {
        cout << "true" << endl;
    } else {
        cout << "false" << endl;
    }

    return 0;
}

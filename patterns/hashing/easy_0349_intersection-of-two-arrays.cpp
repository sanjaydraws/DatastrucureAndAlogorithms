// 349. Intersection of Two Arrays
//https://leetcode.com/problems/intersection-of-two-arrays/description/
/**
 * 
 * 
 * 
 * Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must be unique and you may return the result in any order.
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [9,4]
Explanation: [4,9] is also accepted.
 */
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// Function to find intersection of two arrays
vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
    // Create a set from nums1 to store unique elements
    unordered_set<int> set1(nums1.begin(), nums1.end());

    // This set will store the unique intersection result
    unordered_set<int> result;

    // Traverse nums2 and check if element exists in set1
    for (int num : nums2) {
        if (set1.count(num)) {
            // If it exists, insert into result set (ensures uniqueness)
            result.insert(num);
        }
    }

    // Convert set to vector and return
    return vector<int>(result.begin(), result.end());
}

int main() {
    vector<int> nums1 = {1, 2, 2, 1};
    vector<int> nums2 = {2, 2};

    vector<int> result = intersection(nums1, nums2);
    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

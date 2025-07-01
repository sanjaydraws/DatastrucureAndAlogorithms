// 350. Intersection of Two Arrays II
//easy
//https://leetcode.com/problems/intersection-of-two-arrays-ii/description/


/**
 * 
 * 
 * 
Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order.
Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Explanation: [9,4] is also accepted.
 */


 #include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

//T.c -> O(n + m)    nums1 → takes O(n) nums2 → takes O(m)
//S.c ->	O(min(n, m))
// Function to find intersection (including duplicates)
vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    unordered_map<int, int> count;
    vector<int> result;

    // Count each number in nums1
    for (int num : nums1) {
        count[num]++;
    }

    // Check each number in nums2
    for (int num : nums2) {
        if (count[num] > 0) {
            result.push_back(num); // Add common number
            count[num]--;          // Decrease count
        }
    }

    return result;
}

int main() {
    vector<int> nums1 = {4, 9, 5};
    vector<int> nums2 = {9, 4, 9, 8, 4};

    vector<int> result = intersect(nums1, nums2);

    cout << "Intersection: ";
    for (int num : result) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

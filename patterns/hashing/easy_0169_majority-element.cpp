//169. Majority Element
//Easy
//https://leetcode.com/problems/majority-element/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// Approach 1: Boyer-Moore Voting Algorithm
// Time: O(n), Space: O(1)
// Finds the element that appears more than n/2 times
int majorityElementBoyerMoore(vector<int>& nums) {
    int count = 0;       // Count to track balance between majority and others
    int candidate = 0;   // Current candidate for majority element

    for (int num : nums) {
        if (count == 0) {
            candidate = num;  // Set new candidate when count drops to 0
        }

        // If current number matches candidate, increment count
        // Otherwise, decrement (opposition vote)
        count += (num == candidate) ? 1 : -1;
    }

    // After one full pass, candidate is the majority element
    return candidate;
}


// Approach 2: Hash Map (Frequency Count)
// Time: O(n)
// Space: O(n) // uses extra memory
int majorityElementHashMap(vector<int>& nums) {
    unordered_map<int, int> freq;
    int n = nums.size();
    for (int num : nums) {
        freq[num]++;
        if (freq[num] > n / 2)
            return num;
    }
    return -1; // Problem guarantees majority exists
}

// Approach 3: Sorting (majority element is always at index n/2)
// Time: O(n log n)
// Space: O(1) or O(n) depending on sort
int majorityElementSorting(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    return nums[nums.size() / 2];
}

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    cout << "Input: ";
    for (int num : nums)
        cout << num << " ";
    cout << endl;

    cout << "Boyer-Moore:       " << majorityElementBoyerMoore(nums) << endl;
    cout << "Hash Map:          " << majorityElementHashMap(nums) << endl;
    cout << "Sorting Approach:  " << majorityElementSorting(nums) << endl;

    return 0;
}

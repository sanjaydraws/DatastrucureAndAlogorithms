

//560. Subarray Sum Equals K
// https://leetcode.com/problems/subarray-sum-equals-k/description/


#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// Function to print all subarrays with sum == k using prefix sum + hashmap
void printSubarraysWithSumK(vector<int>& nums, int k) {
    unordered_map<int, vector<int>> prefixMap;  // prefixSum -> list of indices
    prefixMap[0].push_back(-1); // base case: prefixSum = 0 at index -1

    int currSum = 0;

    for (int i = 0; i < nums.size(); i++) {
        currSum += nums[i];

        // Check if there's a prefix sum such that currSum - k = prevSum
        if (prefixMap.find(currSum - k) != prefixMap.end()) {
            for (int startIndex : prefixMap[currSum - k]) {
                cout << "Subarray [" << startIndex + 1 << " to " << i << "]: ";
                for (int j = startIndex + 1; j <= i; j++) {
                    cout << nums[j] << " ";
                }
                cout << endl;
            }
        }

        // Store current prefix sum index
        prefixMap[currSum].push_back(i);
    }
}

// Function to return count of subarrays whose sum = k
int subarraySum(vector<int>& nums, int k) {
    unordered_map<int, int> pc; // Map to store prefix sum frequency
    pc[0] = 1; // Base case: prefix sum 0 occurs once

    int currSum = 0; // Current prefix sum
    int count = 0;   // Count of valid subarrays

    for (int num : nums) {
        currSum += num;

        // If (currSum - k) was seen before, add its count
        if (pc.find(currSum - k) != pc.end()) {
            count += pc[currSum - k];
        }

        // Update map with current prefix sum
        pc[currSum]++;
    }

    return count;
}

int main() {
    vector<int> nums = {1, 1, 1, 1};
    int k = 2;

    // Print all matching subarrays
    cout << "All subarrays with sum = " << k << ":\n";
    printSubarraysWithSumK(nums, k);

    // Count total matching subarrays
    int total = subarraySum(nums, k);
    cout << "\nTotal subarrays with sum = " << k << ": " << total << endl;

    return 0;
}



// Approach	             Works for this problem?             	When?
// Sliding Window	             ❌ Not always	       ❌ Fails if array has negatives
// Prefix Sum + Map	                ✅ Yes	        ✅ Handles both positive & negative nums

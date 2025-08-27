// https://leetcode.com/problems/partition-array-into-k-distinct-groups/description/
// 3659. Partition Array Into K-Distinct Groups



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums, int k) {
        int n = nums.size();

        // Step 1: If n is not divisible by k,
        // then we cannot partition into equal groups
        if (n % k != 0) return false;

        int groups = n / k; // size of each group

        // Step 2: Count frequency of each element
        unordered_map<int,int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        // Step 3: Check frequency condition
        // Each element must appear <= number of groups
        for (auto &it : freq) {
            if (it.second > groups) {
                return false; 
                // If any element appears more times than groups,
                // partition is not possible
            }
        }

        // Step 4: If all conditions satisfied, partitioning is possible
        return true;
    }
};

/*
--------------------------------------------------
Time Complexity (T.C):
- Counting frequencies: O(n)
- Checking conditions: O(unique elements) <= O(n)
=> Overall: O(n)

Space Complexity (S.C):
- HashMap (freq) stores at most n unique elements
=> O(n)
--------------------------------------------------
*/

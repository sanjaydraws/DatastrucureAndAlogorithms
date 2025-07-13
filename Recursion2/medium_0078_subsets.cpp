// 78. Subsets
// Medium
//https://leetcode.com/problems/subsets/description/

// Given an integer array nums of unique elements, return all possible subsets (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.
/**
Example 1:

Input: nums = [1,2,3]
Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
Example 2:

Input: nums = [0]
Output: [[],[0]]
*/

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> subset;
        generateSubsets(nums, 0, subset, result);
        return result;
    }

private:
    void generateSubsets(vector<int>& nums, int index, vector<int>& subset, vector<vector<int>>& result) {
        if (index == nums.size()) {
            result.push_back(subset);
            return;
        }

        // Include current element
        subset.push_back(nums[index]);
        generateSubsets(nums, index + 1, subset, result);

        // Exclude current element (backtrack)
        subset.pop_back();
        generateSubsets(nums, index + 1, subset, result);
    }
};

int main() {
    Solution sol;

    vector<int> nums = {1, 2, 3};
    vector<vector<int>> result = sol.subsets(nums);

    cout << "Subsets:\n";
    for (const auto& subset : result) {
        cout << "[ ";
        for (int num : subset) {
            cout << num << " ";
        }
        cout << "]\n";
    }

    return 0;
}




#include <iostream>
#include <vector>

using namespace std;

/*
    Time Complexity: O(n × n!)
    --------------------------
    - There are n! total permutations.
    - For each permutation, we build a path of length n (O(n) operations).
    - Swapping takes O(1) time, and we do this at every level.
    - So total time = O(n × n!)

    Space Complexity: O(n!) for output + O(n) for recursion stack
    -------------------------------------------------------------
    - O(n!): to store all permutations in the result vector
    - O(n): recursion depth is n
*/

class Solution {
public:
    void recurPermute(int index, vector<int>& nums, vector<vector<int>>& result) {
        // Base case: if current index reached the end, store the permutation
        if (index == nums.size()) {
            result.push_back(nums);
            return;
        }

        // Try placing every number at the current index
        for (int i = index; i < nums.size(); i++) {
            swap(nums[index], nums[i]);             // Choose: swap current index with i
            recurPermute(index + 1, nums, result);  // Explore: move to next index
            swap(nums[index], nums[i]);             // Undo: backtrack to original state
        }
    }

    // start the permutation process
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;                 
        recurPermute(0, nums, result);              // Start from index 0
        return result;
    }
};

int main() {
    Solution obj;
    vector<int> nums = {1, 2, 3};                   

    vector<vector<int>> permutations = obj.permute(nums); 

    cout << "All permutations:\n";
    for (const auto& p : permutations) {
        for (int num : p) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}

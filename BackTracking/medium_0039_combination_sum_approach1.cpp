//https://leetcode.com/problems/combination-sum/description/
// 39. Combination Sum


//Include-Exclude Backtracking Approach 
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(int i, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }
        if (i >= candidates.size() || target < 0) return;

        // Include current element
        path.push_back(candidates[i]);
        solve(i, target - candidates[i], candidates, path, result);
        path.pop_back(); // Backtrack

        // Exclude current element
        solve(i + 1, target, candidates, path, result);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result, path;
        vector<int> temp;
        solve(0, target, candidates, temp, result);
        return result;
    }
};

int main() {
    vector<int> candidates = {2, 3, 5, 7};
    int target = 7;
    Solution sol;
    vector<vector<int>> result = sol.combinationSum(candidates, target);

    for (const auto& comb : result) {
        for (int num : comb)
            cout << num << " ";
        cout << endl;
    }
    return 0;
}

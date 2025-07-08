//https://leetcode.com/problems/combination-sum/description/
// 39. Combination Sum

//Loop-Based Backtracking
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void backtrack(int start, int target, vector<int>& candidates, vector<int>& path, vector<vector<int>>& result) {
        if (target == 0) {
            result.push_back(path);
            return;
        }

        for (int i = start; i < candidates.size(); ++i) {
            if (candidates[i] > target) continue;

            path.push_back(candidates[i]);              // choose
            backtrack(i, target - candidates[i], candidates, path, result); // not i+1 (reuse allowed)
            path.pop_back();                            // un-choose
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> path;
        backtrack(0, target, candidates, path, result);
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

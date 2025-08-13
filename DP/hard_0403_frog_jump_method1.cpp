//403. Frog Jump
// https://leetcode.com/problems/frog-jump/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<int> stones;
    unordered_set<int> stonesSet;

    // Pure Recursion (no memoization)
    bool canCrossRecursive(vector<int>& stonesInput) {
        stones = stonesInput;
        stonesSet.clear();
        for (int s : stones) stonesSet.insert(s);
        return dfsRecursive(0, 0);
    }

    //  Memoized version
    bool canCrossMemoized(vector<int>& stonesInput) {
        stones = stonesInput;
        stonesSet.clear(); // not required if use only one approach
        memo.clear();
        for (int s : stones) stonesSet.insert(s);
        return dfsMemo(0, 0);
    }

private:
    // ----- 1. Recursive (no memoization) -----
    bool dfsRecursive(int pos, int lastJump) {
        if (pos == stones.back()) return true;

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump > 0 && stonesSet.count(pos + jump)) {
                if (dfsRecursive(pos + jump, jump)) {
                    return true;
                }
            }
        }

        return false;
    }

    // ----- 2. Memoization (Top-Down DP) -----
    unordered_map<string, bool> memo;

    bool dfsMemo(int pos, int lastJump) {
        if (pos == stones.back()) return true;

        string key = to_string(pos) + "," + to_string(lastJump);
        if (memo.count(key)) return memo[key];

        for (int jump = lastJump - 1; jump <= lastJump + 1; ++jump) {
            if (jump > 0 && stonesSet.count(pos + jump)) {
                if (dfsMemo(pos + jump, jump)) {
                    return memo[key] = true;
                }
            }
        }

        return memo[key] = false;
    }
};

//403. Frog Jump
// https://leetcode.com/problems/frog-jump/description/

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:

    /*
     1. Tabulation DP (2D array)
    -------------------------------------
    Time Complexity:  O(n^2)
    Space Complexity: O(n^2)

    ✅ Stores reachability of each stone with each jump size.
    ❌ Consumes more space (even for unreachable states).
    */
    bool canCrossTabulation(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        unordered_map<int, int> posToIndex;
        for (int i = 0; i < n; i++) {
            posToIndex[stones[i]] = i;
        }

        vector<vector<bool>> dp(n, vector<bool>(n + 1, false));
        dp[0][0] = true;

        for (int i = 0; i < n; i++) {
            for (int k = 0; k <= n; k++) {
                if (dp[i][k]) {
                    for (int jump = k - 1; jump <= k + 1; jump++) {
                        if (jump > 0) {
                            int nextPos = stones[i] + jump;
                            if (posToIndex.count(nextPos)) {
                                int nextIdx = posToIndex[nextPos];
                                dp[nextIdx][jump] = true;
                            }
                        }
                    }
                }
            }
        }

        for (int k = 0; k <= n; k++) {
            if (dp[n - 1][k]) return true;
        }

        return false;
    }

    /*
     2. Space Optimized DP using Map
    -------------------------------------
    Time Complexity:  O(n^2)
    Space Complexity: O(n^2) in worst case,
                      but much better in practice (sparse)

     Stores only reachable jump sizes for each stone.
    More efficient and scalable for larger inputs.
     Preferred in practice.
    */
    bool canCrossOptimized(vector<int>& stones) {
        int n = stones.size();
        if (stones[1] != 1) return false;

        unordered_map<int, unordered_set<int>> dp;
        dp[0].insert(0);

        unordered_set<int> stoneSet(stones.begin(), stones.end());

        for (int stone : stones) {
            for (int k : dp[stone]) {
                for (int jump = k - 1; jump <= k + 1; jump++) {
                    if (jump > 0 && stoneSet.count(stone + jump)) {
                        dp[stone + jump].insert(jump);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};

int main() {
    Solution sol;
    vector<int> stones = {0, 1, 3, 5, 6, 8, 12, 17};

    cout << "Tabulation DP: ";
    cout << (sol.canCrossTabulation(stones) ? "Can cross ✅" : "Cannot cross ❌") << endl;

    cout << " Space Optimized DP: ";
    cout << (sol.canCrossOptimized(stones) ? "Can cross ✅" : "Cannot cross ❌") << endl;

    return 0;
}

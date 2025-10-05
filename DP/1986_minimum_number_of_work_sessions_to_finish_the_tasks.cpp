// 1986. Minimum Number of Work Sessions to Finish the Tasks
//https://leetcode.com/problems/minimum-number-of-work-sessions-to-finish-the-tasks/description/


/*
| Approach               | Idea                             | When to Use         | Optimal? |
| ---------------------- | -------------------------------- | ------------------- | -------- |
| Brute Force            | Try all task permutations        | Very small n        | Yes      |
| Backtracking + Pruning | Stop paths exceeding best        | n ≤ 14              | Yes      |
| Bitmask DP / Subset DP | DP on task subsets               | n ≤ 14              | Yes      |
| Greedy + DFS           | Fill session as much as possible | Larger n, heuristic | May fail |
| Bitmask + Memoization  | DFS + store results              | n ≤ 14              | Yes      |


*/


//Brutforce
#include <bits/stdc++.h>
using namespace std;

class Solution1 {
public:
    int minSessions(vector<int>& tasks, int sessionTime) {
        int n = tasks.size();
        int res = n; // worst case: each task in its own session

        vector<int> perm = tasks;
        sort(perm.begin(), perm.end()); // start with sorted for next_permutation

        do {
            int count = 1; // start with first session
            int currTime = 0;
            for (int t : perm) {
                if (currTime + t <= sessionTime) {
                    currTime += t; // add task to current session
                } else {
                    count++;       // start new session
                    currTime = t;
                }
            }
            res = min(res, count); // update minimum sessions
        } while (next_permutation(perm.begin(), perm.end()));

        return res;
    }
};



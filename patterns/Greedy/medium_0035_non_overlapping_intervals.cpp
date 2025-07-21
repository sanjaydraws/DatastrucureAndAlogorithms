// 435. Non-overlapping Intervals
// https://leetcode.com/problems/non-overlapping-intervals/description/

#include <bits/stdc++.h>
using namespace std;

/*
Approach:
- Sort intervals based on end time.
- Greedily pick intervals that start after the last chosen one ends.
- Count how many non-overlapping intervals we can keep.
- Answer = total - count (intervals to remove)
*/
//Time Complexity: O(n log n) — due to sorting
// Space Complexity: O(1)
int eraseOverlapIntervals(vector<vector<int>>& intervals) {
    if (intervals.empty()) return 0;

    // Step 1: Sort by end time
    sort(intervals.begin(), intervals.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int count = 1;             // At least one interval can be taken
    int lastEnd = intervals[0][1];

    // Step 2: Traverse and count non-overlapping intervals
    for (int i = 1; i < intervals.size(); ++i) {
        if (intervals[i][0] >= lastEnd) {
            count++;
            lastEnd = intervals[i][1];
        }
    }

    // Step 3: Return how many we need to remove
    return intervals.size() - count;
}

int main() {
    vector<vector<int>> intervals = {{1,2}, {1,3}, {2,3}, {3,4}};
    cout << "Minimum intervals to remove = " << eraseOverlapIntervals(intervals) << endl;
    return 0;
}

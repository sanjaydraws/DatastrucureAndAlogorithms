// 56. Merge Intervals
//https://leetcode.com/problems/merge-intervals/description/
//Time: O(N log N) for sorting + O(N) for traversal → O(N log N)
// Space: O(N) for the result vector
#include <bits/stdc++.h>
using namespace std;

// Function to merge overlapping intervals
vector<vector<int>> merge(vector<vector<int>>& intervals) {
    vector<vector<int>> merged;

    // Step 1: Sort intervals based on start time
    sort(intervals.begin(), intervals.end());

    //  Step 2: Traverse intervals one by one
    for (auto& interval : intervals) {
        int start = interval[0];
        int end = interval[1];

        // If merged list is empty OR no overlap with last interval → simply add
        if (merged.empty() || merged.back()[1] < start) {
            merged.push_back({start, end});
        }
        else {
            // Overlap detected → merge with last interval
            merged.back()[1] = max(merged.back()[1], end);
        }
    }

    return merged;
}

int main() {
    vector<vector<int>> intervals = {{1, 3}, {2, 6}, {8, 10}, {15, 18}};

    vector<vector<int>> result = merge(intervals);

    cout << "Merged Intervals:\n";
    for (auto& interval : result) {
        cout << "[" << interval[0] << ", " << interval[1] << "]\n";
    }

    return 0;
}

// http://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/description/
// 452. Minimum Number of Arrows to Burst Balloons


#include <bits/stdc++.h>
using namespace std;


// Time Complexity	O(n log n) (due to sorting)
// Space Complexity	O(1) (no extra space)
int findMinArrowShots(vector<vector<int>>& points) {
    if (points.empty()) return 0;

    // 🔹 Step 1: Sort balloons by their end position (x_end)
    sort(points.begin(), points.end(), [](vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    });

    int arrows = 1;                         // At least 1 arrow is needed
    int lastArrow = points[0][1];          // Shoot first arrow at end of first balloon

    // 🔹 Step 2: Traverse remaining balloons
    for (int i = 1; i < points.size(); ++i) {
        // If balloon starts after last arrow, we need a new arrow
        if (points[i][0] > lastArrow) {
            arrows++;                      // Shoot new arrow
            lastArrow = points[i][1];     // Update new arrow position
        }
        // Else: balloon gets burst with existing arrow — no action needed
    }

    return arrows;
}

int main() {
    vector<vector<int>> balloons = {{10,16}, {2,8}, {1,6}, {7,12}};

    cout << "Minimum arrows needed: " << findMinArrowShots(balloons) << endl;

    return 0;
}

/*
     Problem: Defense of a Kingdom (Greedy)

    There is a kingdom represented by a grid of width 'w' and height 'h'.
    Some towers are placed on certain grid coordinates. Each tower defends
    its entire row and column (like a queen in chess). All other cells 
    are unprotected.

    You are to find the **maximum unprotected rectangular area** on the grid.

    📥 Input:
      - w: width of the grid (columns)
      - h: height of the grid (rows)
      - towers: list of (x, y) coordinates where towers are located

    📤 Output:
      - Maximum rectangular area on the grid which is not protected by any tower

     Approach:
      - Extract all tower x and y coordinates
      - Sort them to calculate the maximum gap between adjacent towers
      - Consider edges of the grid as well
      - Final answer = max horizontal gap × max vertical gap

     Time Complexity: O(n log n)  // due to sorting
     Space Complexity: O(n)      // storing tower coordinates
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to compute the maximum unprotected area
int defenseOfKingdom(int w, int h, vector<pair<int, int>>& towers) {
    if (towers.empty()) return w * h; // No towers, entire area is unprotected

    // Separate x and y coordinates of towers
    vector<int> xCord, yCord;
    for (auto& t : towers) {
        xCord.push_back(t.first);
        yCord.push_back(t.second);
    }

    // Sort the coordinates to find max gaps
    sort(xCord.begin(), xCord.end());
    sort(yCord.begin(), yCord.end());

    // Calculate maximum horizontal gap between towers (columns)
    int maxXGap = xCord[0] - 1; // From left edge to first tower
    for (int i = 1; i < xCord.size(); i++) {
        maxXGap = max(maxXGap, xCord[i] - xCord[i - 1] - 1); // gap between towers
    }
    maxXGap = max(maxXGap, w - xCord.back()); // From last tower to right edge

    // Calculate maximum vertical gap between towers (rows)
    int maxYGap = yCord[0] - 1; // From bottom to first tower
    for (int i = 1; i < yCord.size(); i++) {
        maxYGap = max(maxYGap, yCord[i] - yCord[i - 1] - 1); // gap between towers
    }
    maxYGap = max(maxYGap, h - yCord.back()); // From last tower to top edge

    // The max unprotected area = largest unprotected width × height
    return maxXGap * maxYGap;
}

// Main driver
int main() {
    int w = 15, h = 8;
    vector<pair<int, int>> towers = {{3, 4}, {11, 4}};

    int maxArea = defenseOfKingdom(w, h, towers);
    cout << "Maximum Unprotected Area = " << maxArea << endl;

    return 0;
}

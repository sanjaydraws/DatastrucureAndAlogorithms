//455. Assign Cookies
//https://leetcode.com/problems/assign-cookies/description/

#include <bits/stdc++.h>
using namespace std;

/*
Problem: Assign cookies to children to maximize content children.
Approach: Greedy — Sort both arrays, and assign smallest sufficient cookie to each child.

Time Complexity: O(n log n + m log m) — Sorting both arrays
Space Complexity: O(1) — No extra space used
*/

int findContentChildren(vector<int>& g, vector<int>& s) {
    sort(g.begin(), g.end());  // Sort greed factors
    sort(s.begin(), s.end());  // Sort cookie sizes

    int child = 0; // Index for greed
    int cookie = 0; // Index for cookie

    while (child < g.size() && cookie < s.size()) {
        if (s[cookie] >= g[child]) {
            // This cookie satisfies this child
            child++;
        }
        // Whether satisfied or not, move to next cookie
        cookie++;
    }

    return child; // Number of children satisfied
}

int main() {
    vector<int> g = {1, 2};
    vector<int> s = {1, 2, 3};

    cout << "Maximum content children = " << findContentChildren(g, s) << endl;
    return 0;
}

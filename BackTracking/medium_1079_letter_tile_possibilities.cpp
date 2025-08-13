// https://leetcode.com/problems/letter-tile-possibilities/description/
// 1079. Letter Tile Possibilities

#include <bits/stdc++.h>
using namespace std;

/*
    Problem: Letter Tile Possibilities
    Input: A string of tiles (e.g., "AAB")
    Output: Total number of possible non-empty sequences

    Time Complexity (T.C): 
        - Worst Case: O(N! × 26)
        - Because for each tile, we try all combinations recursively, but avoid duplicates using frequency pruning.
        - N = length of input string

    Auxiliary Space Complexity (A.S.C):
        - O(26) for the frequency array (fixed)
        - O(N) recursion depth for backtracking
        - Total A.S.C = O(N)
*/

// Recursive backtracking function to count all valid sequences
int backtrack(vector<int>& freq) {
    int total = 0;

    for (int i = 0; i < 26; ++i) {
        if (freq[i] == 0) continue;

        // Choose the current character ('A' + i)
        total++;         // Count this single choice as 1 valid sequence
        freq[i]--;       // Use one occurrence

        total += backtrack(freq);  // Explore further combinations

        freq[i]++;       // Backtrack to restore state
    }

    return total;
}

// Main function to prepare frequency array and start backtracking
int numTilePossibilities(string tiles) {
    vector<int> freq(26, 0);  // Frequency of each letter A-Z

    for (char ch : tiles) {
        freq[ch - 'A']++;     // Count each character
    }

    return backtrack(freq);
}

int main() {
    string tiles = "AAB";
    cout << numTilePossibilities(tiles) << endl;  // Output: 8
    return 0;
}

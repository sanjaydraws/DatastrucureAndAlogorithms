// Leetcode 771: Jewels and Stones
// Easy
// Problem: Count how many stones are also jewels

#include <iostream>
#include <unordered_set>
using namespace std;

// Time (T.C)	O(n + m)	n = length of jewels, m = stones
// Space (S.C)	O(n)	To store jewels in unordered_set
// Function to count how many stones are jewels
int numJewelsInStones(string jewels, string stones) {
    unordered_set<char> jewelSet; // To store jewel types for quick lookup

    // Step 1: Add each jewel character to the set
    for (char c : jewels) {
        jewelSet.insert(c);
    }

    // Step 2: Check each stone; if it's a jewel, increment count
    int count = 0;
    for (char c : stones) {
        if (jewelSet.count(c)) {
            count++;
        }
    }

    return count; // Total jewels found in stones
}

int main() {
    // Example inputs
    string jewels = "aA";
    string stones = "aAAbbbb";

    // Call the function and print the result
    int result = numJewelsInStones(jewels, stones);
    cout << "Number of jewels in stones: " << result << endl;

    return 0;
}

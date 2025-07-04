// 202. Happy Number
// https://leetcode.com/problems/happy-number/description/

/*
Example 1:

Input: n = 19
Output: true
Explanation:
1² + 9² = 82
8² + 2² = 68
6² + 8² = 100
1² + 0² + 0² = 1

Example 2:

Input: n = 2
Output: false
*/

#include <iostream>
#include <unordered_set>
using namespace std;

// Helper function to calculate the sum of the squares of digits
int getNext(int n) {
    int sum = 0;
    while (n > 0) {
        int digit = n % 10;      // Get last digit
        sum += digit * digit;    // Square and add to sum
        n /= 10;                 // Remove last digit
    }
    return sum;
}

// --------------------------------------------
// Approach 1: HashSet to detect cycle |  Set-based cycle detection method:
// Time Complexity = O(log n) (due to number of digits in each getNext call, done for constant number of iterations)
//  Space Complexity = O(1) (constant space — set grows only up to a limited number of unique values)
// Function to check if a number is a happy number
bool isHappy_HashSet(int n) {
    unordered_set<int> seen; // Set to track numbers we've already seen

    while (n != 1 && seen.find(n) == seen.end()) {
        seen.insert(n);
        n = getNext(n);
    }

    return n == 1;
}

// --------------------------------------------
// Approach 2: Floyd's Cycle Detection (Tortoise and Hare)
// T.C = O(log n), S.C = O(1)
bool isHappy_Floyd(int n) {
    int slow = n;
    int fast = getNext(n);

    while (fast != 1 && slow != fast) {
        slow = getNext(slow);                 // Move slow 1 step
        fast = getNext(getNext(fast));        // Move fast 2 steps
    }

    return fast == 1;
}

// --------------------------------------------

int main() {
    int n = 19;

    cout << "Using HashSet approach:\n";
    if (isHappy_HashSet(n))
        cout << n << " is a happy number.\n";
    else
        cout << n << " is not a happy number.\n";

    cout << "\nUsing Floyd’s Cycle Detection approach:\n";
    if (isHappy_Floyd(n))
        cout << n << " is a happy number.\n";
    else
        cout << n << " is not a happy number.\n";

    return 0;
}

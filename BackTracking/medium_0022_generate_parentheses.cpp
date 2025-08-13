#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    vector<string> result;

    // Main function
    vector<string> generateParenthesis(int n) {
        string current = "";
        backtrack(n, 0, 0, current);
        return result;
    }

    // Recursive function to build valid strings
    void backtrack(int n, int open, int close, string current) {
        // Base case: if the string is complete
        if (current.length() == 2 * n) {
            result.push_back(current);
            return;
        }

        // Add '(' if we have less than n opens
        if (open < n) {
            backtrack(n, open + 1, close, current + '(');
        }

        // Add ')' only if we have more opens than closes
        if (close < open) {
            backtrack(n, open, close + 1, current + ')');
        }
    }
};


/*
----------------------------------------------------
 Time Complexity: O(4^n / √n)
- The number of valid parentheses strings for n pairs is the nth Catalan number
- Catalan(n) ≈ 4^n / (n^1.5)
- Each valid combination takes O(n) time to build

Space Complexity: O(4^n / √n * n)
- Result stores ~Catalan(n) strings, each of length up to 2n → O(4^n / √n * n)
- Stack space for recursion = O(n) due to recursion depth
----------------------------------------------------
*/
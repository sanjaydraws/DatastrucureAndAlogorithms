// https://leetcode.com/problems/letter-combinations-of-a-phone-number/submissions/1692144294/
// 17. Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    // Stores all possible combinations
    vector<string> result;

    // Mapping of digits to corresponding letters
    vector<string> phoneMap = {
        "",     // 0
        "",     // 1
        "abc",  // 2
        "def",  // 3
        "ghi",  // 4
        "jkl",  // 5
        "mno",  // 6
        "pqrs", // 7
        "tuv",  // 8
        "wxyz"  // 9
    };

    // Main function that starts the backtracking process
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {}; // Handle empty input case
        solve(digits, "", 0);
        return result;
    }

    // Recursive backtracking function
    void solve(string& digits, string current, int index) {
        // Base case: full combination formed
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        // Get the possible letters for current digit
        string letters = phoneMap[digits[index] - '0'];

        // Explore all possibilities
        for (char ch : letters) {
            solve(digits, current + ch, index + 1);
        }
    }
};

/*
 Time Complexity: O(4^n)
- Each digit can map to 3 or 4 letters (worst case: 4 letters for digits 7 and 9)
- If input has n digits, total combinations = up to 4^n

 Space Complexity: O(4^n × n)
- There are up to 4^n combinations
- Each combination string has length up to n
- Additional O(n) stack space used for recursion
*/

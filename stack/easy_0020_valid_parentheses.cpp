// 20. Valid Parentheses
// https://leetcode.com/problems/valid-parentheses/description/

// Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

// An input string is valid if:

// Open brackets must be closed by the same type of brackets.
// Open brackets must be closed in the correct order.
// Every close bracket has a corresponding open bracket of the same type.
 

// Example 1:

// Input: s = "()"

// Output: true

// Example 2:

// Input: s = "()[]{}"

// Output: true

// Example 3:

// Input: s = "(]"

// Output: false

// Example 4:

// Input: s = "([])"

// Output: true

 

#include <stack>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:

    //Time: O(n) – where n is the length of the string.
    // Space: O(n) – in the worst case, all characters are pushed onto the stack.
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char ch : s) {
            // If it's a closing bracket
            if (bracketMap.count(ch)) {
                if (!stk.empty() && stk.top() == bracketMap[ch]) {
                    stk.pop();
                } else {
                    return false;
                }
            } else {
                // It's an opening bracket
                stk.push(ch);
            }
        }

        return stk.empty();
    }
};

// https://leetcode.com/problems/basic-calculator-ii/description/
// 227. Basic Calculator II


#include <iostream>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int calculate(string s) {
        stack<int> stk;
        int num = 0;
        char sign = '+'; // Default to '+' for the first number

        for (int i = 0; i < s.length(); ++i) {
            char ch = s[i];

            // Step 1: If digit, build the number (multi-digit support)
            if (isdigit(ch)) {
                num = num * 10 + (ch - '0');
            }

            // Step 2: If current char is an operator or last char, process previous sign
            if ((!isdigit(ch) && ch != ' ') || i == s.length() - 1) {
                if (sign == '+') {
                    stk.push(num);
                } else if (sign == '-') {
                    stk.push(-num);
                } else if (sign == '*') {
                    int top = stk.top(); stk.pop();
                    stk.push(top * num);
                } else if (sign == '/') {
                    int top = stk.top(); stk.pop();
                    stk.push(top / num); // Integer division truncates toward zero
                }

                sign = ch; // Update sign for next operation
                num = 0;   // Reset number builder
            }
        }

        // Step 3: Sum all values in the stack
        int result = 0;
        while (!stk.empty()) {
            result += stk.top();
            stk.pop();
        }

        return result;
    }
};

int main() {
    Solution sol;
    
    string expression = "3+5 / 2"; // You can change this to test other inputs
    cout << "Result: " << sol.calculate(expression) << endl; // Output: 5

    return 0;
}

/*
Time Complexity	O(n)
Space Complexity	O(n)
*/
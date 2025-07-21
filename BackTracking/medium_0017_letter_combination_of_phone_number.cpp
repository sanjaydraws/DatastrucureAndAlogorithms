#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> map = {
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

    // ----------- Approach 1: Using current + ch (String copy) -----------
    /*
    Time Complexity: O(4^n)
        - Each digit maps to at most 4 letters (like 7 and 9).
        - So total combinations: 3^x * 4^y (where x = #digits with 3 letters, y = #digits with 4 letters)
    Space Complexity: O(n)
        - Recursion stack space = depth of the tree = length of digits
    */
    vector<string> letterCombinations_v1(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        solve_v1(digits, "", 0, res);
        return res;
    }

    void solve_v1(string& digits, string current, int index, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(current);
            return;
        }

        string letters = map[digits[index] - '0'];
        for (char ch : letters) {
            solve_v1(digits, current + ch, index + 1, res);  // create new string each time
        }
    }

    // ----------- Approach 2: Using push_back and pop_back (True Backtracking) -----------
    /*
    Time Complexity: Same as above: O(4^n)
    Space Complexity:
        - O(n) for recursion stack
        - O(n) extra for 'path' string which is modified in-place
    */
    vector<string> letterCombinations_v2(string digits) {
        vector<string> res;
        if (digits.empty()) return res;

        string path;
        solve_v2(digits, 0, path, res);
        return res;
    }

    void solve_v2(string& digits, int index, string& path, vector<string>& res) {
        if (index == digits.size()) {
            res.push_back(path);
            return;
        }

        string letters = map[digits[index] - '0'];
        for (char ch : letters) {
            path.push_back(ch);                   // pick
            solve_v2(digits, index + 1, path, res);
            path.pop_back();                      // backtrack
        }
    }
};

int main() {
    Solution sol;
    string digits;
    cout << "Enter digit string (2-9): ";
    cin >> digits;

    cout << "\nApproach 1 (Using current + ch):" << endl;
    vector<string> result1 = sol.letterCombinations_v1(digits);
    for (const string& s : result1) {
        cout << s << " ";
    }

    cout << "\n\nApproach 2 (Using push_back / pop_back):" << endl;
    vector<string> result2 = sol.letterCombinations_v2(digits);
    for (const string& s : result2) {
        cout << s << " ";
    }

    cout << endl;
    return 0;
}

// https://leetcode.com/problems/palindromic-substrings/
/**

Input: s = "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".
*/
#include <iostream>
#include <string>

using namespace std;
class Solution {
public:
    int expand(std::string s, int i, int j) {
        int count = 0;
        while (i >= 0 && j < s.length() && s[i] == s[j]) {
            count++;
            i--;
            j++;
        }
        return count;
    }

    int countSubstrings(std::string s) {
        int totalCount = 0;
        for (int i = 0; i < s.length(); i++) {
            // Odd length palindromes
            int oddAns = expand(s, i, i);

            // Even length palindromes
            int evenAns = expand(s, i, i + 1);

            totalCount = totalCount + oddAns + evenAns;
        }
        return totalCount;
    }
};

int main() {
    Solution solution;
    string input = "aaa";

    int result = solution.countSubstrings(input);

    cout << "Number of palindromic substrings in '" << input << "': " << result << endl;

    return 0;
}
/*
Number of palindromic substrings in 'aaa': 6

*/

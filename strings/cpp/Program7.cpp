// https://leetcode.com/problems/valid-palindrome-ii/

#include <iostream>
using namespace std;
class Solution {
public:
    bool checkPalindrome(string s, int i, int j) {
        while (i <= j) {
            if (s[i] != s[j]) {
                return false;
            } else {
                i++;
                j--;
            }
        }
        return true;
    }

    bool validPalindrome(string s) {
        int i = 0;
        int j = s.length() - 1;

        while (i <= j) {
            if (s[i] == s[j]) {
                i++;
                j--;
            } else {
                // If elements not matched on the left and right, 
                // 1 removal allowed
                
                // s[i] != s[j]
                // Check palindrome for the remaining string after removal

                // ith character -> remove
                bool ans1 = checkPalindrome(s, i + 1, j);
                // jth character -> remove
                bool ans2 = checkPalindrome(s, i, j - 1);

                return ans1 || ans2;
            }
        }
        // If reached here, it means valid palindrome (0 removal)
        return true;
    }
};

int main() {
    Solution solution;
    string input = "abca";

    bool result = solution.validPalindrome(input);

    cout << "Is '" << input << "' a valid palindrome? " << (result ? "Yes" : "No") << endl;

    return 0;
}

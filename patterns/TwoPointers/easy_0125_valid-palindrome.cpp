// 125. Valid Palindrome
// Easy
// https://leetcode.com/problems/valid-palindrome/description/

/**
 * 
 *  
Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
 */
//Alphanumeric characters includes( a–z, A–Z Digits: 0–9)


#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool isPalindrome(string s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
        if (!isalnum(s[left])) {
            left++;
            continue;
        }

        if (!isalnum(s[right])) {
            right--;
            continue;
        }

        if (tolower(s[left]) != tolower(s[right])) {
            return false;
        }

        left++;
        right--;
    }

    return true;
}

int main() {
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    if (isPalindrome(input)) {
        cout << "It is a valid palindrome." << endl;
    } else {
        cout << "It is not a valid palindrome." << endl;
    }

    return 0;
}
/**
 * 
 * 
 * Enter a string: A man, a plan, a canal: Panama
It is a valid palindrome.
 */
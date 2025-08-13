// 387. First Unique Character in a String
// Easy
/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

 Example 1:

Input: s = "leetcode"

Output: 0

Explanation:

The character 'l' at index 0 is the first character that does not occur at any other index.

Example 2:

Input: s = "loveleetcode"

Output: 2

Example 3:

Input: s = "aabb"

Output: -1

 */

 #include <iostream>
#include <string>
using namespace std;

int firstUniqChar(string s) {
    int count[26] = {0};  // To store frequency of each letter

    // Step 1: Count frequency of each character
    for (char c : s) {
        count[c - 'a']++;
    }

    // Step 2: Find first character with frequency 1
    for (int i = 0; i < s.length(); i++) {
        if (count[s[i] - 'a'] == 1)
            return i;
    }

    return -1;  // No unique character found
}

int main() {
    string s = "leetcode";

    int index = firstUniqChar(s);
    if (index != -1)
        cout << "First unique character is at index: " << index << endl;
    else
        cout << "No unique character found." << endl;

    return 0;
}

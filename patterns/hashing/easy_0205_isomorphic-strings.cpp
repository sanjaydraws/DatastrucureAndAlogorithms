// https://leetcode.com/problems/isomorphic-strings/description/
// 205. Isomorphic Strings

//Two strings s and t are isomorphic if the characters in s can be replaced to get t.

/*

All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.

 

Example 1:

Input: s = "egg", t = "add"

Output: true

Explanation:

The strings s and t can be made identical by:

Mapping 'e' to 'a'.
Mapping 'g' to 'd'.

Example 2:

Input: s = "foo", t = "bar"

Output: false

Explanation:

The strings s and t can not be made identical as 'o' needs to be mapped to both 'a' and 'r'.

Example 3:

Input: s = "paper", t = "title"

Output: true
*/
#include <iostream>
#include <unordered_map>
using namespace std;

// Function to check if two strings are isomorphic
bool isIsomorphic(string s, string t) {
    // If lengths differ, they can't be isomorphic
    if (s.length() != t.length()) return false;

    unordered_map<char, char> mapS; // Map from s → t
    unordered_map<char, char> mapT; // Map from t → s

    for (int i = 0; i < s.length(); ++i) {
        char c1 = s[i]; // character from string s
        char c2 = t[i]; // character from string t

        // If c1 is already mapped, check if it maps to c2
        if (mapS.count(c1) && mapS[c1] != c2)
            return false;

        // If c2 is already mapped from another char, return false
        if (mapT.count(c2) && mapT[c2] != c1)
            return false;

        // Add new character mapping
        mapS[c1] = c2;
        mapT[c2] = c1;
    }

    // All characters mapped consistently
    return true;
}

int main() {
    string s = "egg";
    string t = "add";

    if (isIsomorphic(s, t))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

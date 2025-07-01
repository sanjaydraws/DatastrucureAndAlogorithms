// https://leetcode.com/problems/valid-anagram/description/
//242. Valid Anagram
//Easy

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

// Frequency array method
bool isAnagramArray(string s, string t) {
    // If strings are of different lengths, they can't be anagrams
    if (s.length() != t.length()) return false;

    // Create a count array to store frequency of each letter (a-z)
    int count[26] = {0};

    for (int i = 0; i < s.length(); i++) {
        // Increment count for character in s
        // Mapping: 'a' → 0, 'b' → 1, ..., 'z' → 25
        count[s[i] - 'a']++;

        // Decrement count for character in t
        count[t[i] - 'a']--;
    }

    // If both strings are anagrams, all counts should be zero
    for (int i = 0; i < 26; i++)
        if (count[i] != 0) return false;

    // Strings are anagrams
    return true;
}


// Sort method
bool isAnagramSort(string s, string t) {
    if (s.length() != t.length()) return false;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    return s == t;
}

int main() {
    string s, t;
    cin >> s >> t;

    if (isAnagramArray(s, t)) cout << "Anagram\n";
    else cout << "Not Anagram\n";

    if (isAnagramSort(s, t)) cout << "Anagram\n";
    else cout << "Not Anagram\n";

    return 0;
}

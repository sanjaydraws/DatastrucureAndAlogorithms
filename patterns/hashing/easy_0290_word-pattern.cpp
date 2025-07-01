

// 290. Word Pattern
//https://leetcode.com/problems/word-pattern/description/


/**
 Example 1:

Input: pattern = "abba", s = "dog cat cat dog"

Output: true

Explanation:

The bijection can be established as:

'a' maps to "dog".
'b' maps to "cat".


Example 2:

Input: pattern = "abba", s = "dog cat cat fish"

Output: false
 */



#include <iostream>
#include <sstream>
#include <unordered_map>
#include <vector>
using namespace std;

// Function to check if string s follows the given pattern
bool wordPattern(string pattern, string s) {
    istringstream iss(s);
    vector<string> words;
    string word;

    // Split s into words using stringstream
    while (iss >> word) {
        words.push_back(word);
    }

    // If lengths differ, pattern can't match
    if (pattern.length() != words.size()) return false;

    unordered_map<char, string> charToWord; // pattern → word
    unordered_map<string, char> wordToChar; // word → pattern

    for (int i = 0; i < pattern.length(); ++i) {
        char c = pattern[i];
        string w = words[i];

        // Check if current pattern char is already mapped
        if (charToWord.count(c) && charToWord[c] != w)
            return false;

        // Check if current word is already mapped to a different character
        if (wordToChar.count(w) && wordToChar[w] != c)
            return false;

        // Add the mappings
        charToWord[c] = w;
        wordToChar[w] = c;
    }

    return true;
}

int main() {
    string pattern = "abba";
    string s = "dog cat cat dog";

    if (wordPattern(pattern, s))
        cout << "true" << endl;
    else
        cout << "false" << endl;

    return 0;
}

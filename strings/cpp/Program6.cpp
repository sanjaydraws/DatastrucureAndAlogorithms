// https://leetcode.com/problems/remove-all-occurrences-of-a-substring/

#include <iostream>

using namespace std;
class Solution {
public:
    string removeOccurrences(string s, string part) {
        while (s.find(part) != string::npos) {
            s.erase(s.find(part), part.length());
        }
        return s;
    }
};

int main() {
    Solution solution;
    string input = "abacaba";
    string substringToRemove = "aba";

    string result = solution.removeOccurrences(input, substringToRemove);

    cout << "Original String: " << input << std::endl;
    cout << "String after removing occurrences of '" << substringToRemove << "': " << result << endl;

    return 0;
}
/*
Original String: abacaba
String after removing occurrences of 'aba': c
*/
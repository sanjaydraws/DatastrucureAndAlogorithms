//https://leetcode.com/problems/remove-all-adjacent-duplicates-in-string/description/

#include <iostream>
using namespace std;
class Solution {
public:

    // T.C - O(n)
    string removeDuplicates(string s) {
        string ans = "";
        int index = 0;

        while (index < s.length()) {
            if (ans.length() > 0 && ans[ans.length() - 1] == s[index]) {
                ans.pop_back();
            } else {
                ans.push_back(s[index]);
            }
            index++;
        }
        return ans;
    }
};

int main() {
    Solution solution;
    string input = "abbaca";

    string result = solution.removeDuplicates(input);

    cout << "Original String: " << input << std::endl;
    cout << "String after removing duplicates: " << result << std::endl;

    return 0;
}

/**
 Original String: abbaca
String after removing duplicates: ca 
*/
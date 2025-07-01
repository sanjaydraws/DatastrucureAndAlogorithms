
// 344. Reverse String
// https://leetcode.com/problems/reverse-string/description/




#include <iostream>
#include <vector>
using namespace std;

// Time: O(n)
// Space: O(1)
void reverseString(vector<char>& s) {
    int left = 0;
    int right = s.size() - 1;

    while (left < right) {
        swap(s[left], s[right]);
        left++;
        right--;
    }
}

int main() {
    vector<char> s = {'h', 'e', 'l', 'l', 'o'};

    cout << "Original string: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    reverseString(s);

    cout << "Reversed string: ";
    for (char c : s) {
        cout << c << " ";
    }
    cout << endl;

    return 0;
}

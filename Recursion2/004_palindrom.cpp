#include <iostream>
using namespace std;

// Time Complexity: O(n)

// Space Complexity: O(n) (stack only)
// palindrome single pointers
bool f(int i, const string& s){
    if(i >=s.size()/2) return true ;
    if(s[i] != s[s.size()-i-1]) return false;
    return f(i+1,s);
}

int main() {

    string s1 = "madam";
    cout<<f(0, s1); // 1

    string s2 = "maxdam";
    cout<<f(0, s2); // 0

    return 0;
}

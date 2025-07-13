#include <iostream>
using namespace std;

// fibbonacci series
int f(int n){
    // n==0, n==1 both case return n
    if(n<=1) return n;
    int last = f(n-1);
    int sLast = f(n-2);
    return last + sLast;
}


int main() {
    int n =4;
    cout<<f(n)<<endl; // 3
    return 0;
}
/**
Total calls: 9 for f(4) → grows rapidly as n increases.

Time Complexity: O(2^n) → exponential time complexity.

*/
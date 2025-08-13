// functional and parameterized recursion


// sum of N Numbers
// factorial
//T.c O(n)
//S.c O(n)
// functional and parameterized recursion





//T.c O(n)
//S.c O(n)
#include <iostream>
using namespace std;

//parameterized recursion
////sum of n numbers
void sumNum(int i, int sum){
    if(i<1) {
        cout<<sum;
        return;
    }
    sumNum(i-1, sum + i);
}
// functional recursion
//sum of n numbers
int sumNum2(int n){
    if(n == 0) {
        return 0;
    }
    return n + sumNum2(n - 1);
}
// factorial
int fact(int n){
    // also work in if(n == 1) return 1;
    if(n == 0) {
        return 1;
    }
    return n * fact(n - 1);
}
int main() {
    sumNum(3,0);//6
    cout<<endl;
    cout<<sumNum2(3);//6
    cout<<endl;
    cout<<fact(3);//6
  return 0;
}


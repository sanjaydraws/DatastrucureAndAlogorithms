

//  print 5 times name
//T.c O(n)
//S.c O(n)
#include <iostream>
using namespace std;

void f(int i, int n){
    if(i>n) return; 
    cout<<"Sanjay"<<endl;
    f(i+1,n);
}
// 4 to 1 print
void f2(int i){
    if(i<1) return; 
    cout<<i<<endl;
    f2(i-1);
}
// 1 to n print
void f3(int i,int n){
    if(i>n) return; 
    cout<<i<<endl;
    f3(i+1,n);
}

// 1 to n print
void f4Bt(int i,int n){
    if(i<1) return; 
    f4Bt(i-1,n);
    cout<<i<<endl;
}

int main() {
  f(1,5);
  f2(4);
  f3(1,4);
  f4Bt(3,3);
    
  return 0;
}


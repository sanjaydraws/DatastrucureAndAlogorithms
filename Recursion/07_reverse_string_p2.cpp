// print a string in reverse 
// abcd -> dcba 
// T.c      O(n) 
// n represents height of string 
#include <iostream>
using namespace std ;

void printReverse(const string&  str, int idx){
    if(idx == 0){
       cout<<str[idx]<<endl;
       return ;
    }
    cout<<str[idx];
    printReverse(str, idx -1 );
}

int main(){
     string str ="Hello";
     printReverse("Hello", str.length());
}
//olleH
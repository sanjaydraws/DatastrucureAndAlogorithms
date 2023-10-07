/*
Call by Value:
when passing function an argument to function by value,copy of the argument's value is  passed to function
Any changes made to the parameter inside the function do not affect the original argument.

Call by Reference:
When you pass an argument by reference, you are passing a reference (or memory address) to the original variable.
Any changes made to the parameter inside the function affect the original argument.
**/
#include <iostream>
using namespace std;

// call by value example 
void increment1(int x) {
    x++; // Changes are made to the copy, not the original
    cout<<"x = "<<x<<endl; // x = 6
}
void increment2(int &x) {
    x++; // Changes are made to the original
    cout<<"x ="<<x<<endl; // x = 6
}

int main(){
    int num = 5;
    // passing value
    increment1(num);
    cout<<num; // Output: 5
    increment2(num); 
    cout<<num; // Output: 6
    return 0;
}
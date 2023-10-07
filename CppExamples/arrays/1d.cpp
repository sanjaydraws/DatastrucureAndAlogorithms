


#include <iostream>
using namespace std;


int main(){
    int numbers[5]; // Creates an array of 5 integers
    //Initializing Arrays:
    int myArray[5] = {10, 20, 30, 40, 50};// Creates an array with initial values 10, 20, 30
    //Initializing Partial Elements:
    int myArray2[5] = {1, 2};
    //Initializing with Uniform Initialization (C++11 onwards):
    int myArray3[] = {1, 2, 3, 4, 5}; // Compiler deduces the size to be 5

    int* ptr = myArray; // Pointer to the first element


    // Using a for loop to access elements
    cout<<"Using a for loop to access elements"<<endl;
    for(int i = 0; i < 5; i++) {
        cout << myArray[i] << " ";
    } // 10 20 30 40 50 
    cout<<endl;
    cout<<"Using a loop and pointer arithmetic to access elements"<<endl;
    for(int i = 0; i < 5; i++) {
        cout << *(ptr + i) << " ";
    } //10 20 30 40 50
    return 0;
}
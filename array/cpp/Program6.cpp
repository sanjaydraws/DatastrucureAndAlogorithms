
// enter 5 values from user , insert in array and print array elements
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE];

    cout << "Please enter " << SIZE << " values:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "Value " << i+1 << ": ";
        cin >> numbers[i];
    }

    cout << "\nYou entered the following values:" << endl;

    for (int i = 0; i < SIZE; i++) {
        cout << "Value " << i+1 << ": " << numbers[i] << endl;
    }

    return 0;
}

/*
Please enter 5 values:
Value 1: 1
Value 2: 3
Value 3: 5
Value 4: 6
Value 5: 8

You entered the following values:
Value 1: 1
Value 2: 3
Value 3: 5
Value 4: 6
Value 5: 8
**/
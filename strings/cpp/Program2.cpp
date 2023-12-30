
// demo of string
#include <iostream>
#include <string.h>

using namespace std;

int main() {
    //creation
    string name;

    //input
    // //cin >> name;
    getline(cin, name);

    cout << "Printing name: " << name << endl;
    cout << "Printing first character: " << name[0] << endl;

    // traverse character from string
    int index = 0;
    while (name[index] != '\0') {
        cout << "Index: " << index << " Character: " << name[index] << endl;
        index++;
    }
    int value = (int)name[6];
    cout << "Integer Value Of 6th index character: " << value << endl;

    return 0;
}

/**
Output:
Rohit Sharma
Printing name: Rohit Sharma
Printing first character: R
Index: 0 Character: R
Index: 1 Character: o
Index: 2 Character: h
Index: 3 Character: i
Index: 4 Character: t
Index: 5 Character:  
Index: 6 Character: S
Index: 7 Character: h
Index: 8 Character: a
Index: 9 Character: r
Index: 10 Character: m
Index: 11 Character: a
Integer Value Of 6th index character: 83

*/
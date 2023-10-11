// Cpp program to shift elements of a single dimensional array in the right direction by one position

#include <iostream>
using namespace std;

void shiftRight(int arr[], int size) {
    int temp = arr[size-1];
    for(int i = size-1; i > 0; i--) {
        arr[i] = arr[i-1];
    }
    arr[0] = temp;
}

int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int size = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    shiftRight(arr, size);

    cout << "Array after shifting right: ";
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
// output
// Original array: 1 2 3 4 5 
// Array after shifting right: 5 1 2 3 4 
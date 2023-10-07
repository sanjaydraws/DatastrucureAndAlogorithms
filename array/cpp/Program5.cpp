// find element in an array
// linear search

#include <iostream>
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; // Return the index if target is found
        }
    }
    return -1; // Return -1 if target is not found
}

int main() {
    int numbers[] = {5, 2, 8, 1, 6};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int target = 8;
    int result = linearSearch(numbers, size, target);

    if (result != -1) {
        cout << "Element " << target << " found at index " << result << endl;
    } else {
        cout << "Element " << target << " not found in the array" << endl;
    }

    return 0;
}

// output 
// Element 8 found at index 2
#include <iostream>
using namespace std;

//  Bubble Sort Algorithm
//  Time Complexity:
//    - Best Case:    O(n)       (if already sorted, with optimization)
//    - Average Case: O(n^2)
//    - Worst Case:   O(n^2)
//  Space Complexity:
//    - O(1) → In-place sorting

// Function to perform Bubble Sort
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        bool swapped = false;

        // Perform a pass to bubble up the largest element
        for (int j = 0; j < n - i - 1; ++j) {
            // Compare adjacent elements
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true; // A swap happened
            }
        }

        //  Optimization: stop if no swaps occurred (already sorted)
        if (!swapped) break;
    }
}

// Function to print the array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Main function
int main() {
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    bubbleSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

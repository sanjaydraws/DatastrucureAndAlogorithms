#include <iostream>
using namespace std;

// 🌟 Selection Sort Algorithm
// Time Complexity:
//    - Best Case:    O(n^2)
//    - Average Case: O(n^2)
//    - Worst Case:   O(n^2)
// Space Complexity:
//    - O(1) → In-place sorting, no extra memory used

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; ++i) {
        // Assume the current element is the minimum
        int minIndex = i;

        // Find the index of the actual minimum element in the unsorted part
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        // ✅ Only swap if the current element is not already the minimum
        //    This avoids unnecessary swaps
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }
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
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Original array: ";
    printArray(arr, n);

    selectionSort(arr, n);

    cout << "Sorted array: ";
    printArray(arr, n);

    return 0;
}

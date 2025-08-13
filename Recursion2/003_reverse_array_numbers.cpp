#include <iostream>
#include <algorithm>
using namespace std;

// Reverse using two pointers
void reverse1(int l, int r, int arr[]) {
    if (l >= r) return;
    swap(arr[l], arr[r]);
    reverse1(l + 1, r - 1, arr);
}

// Reverse using single pointer
void reverse2(int i, int n, int arr[]) {
    if (i >= n / 2) return;
    swap(arr[i], arr[n - i - 1]);
    reverse2(i + 1, n, arr);
}

int main() {
    int n;
    cout << "Enter size of array: ";
    cin >> n;

    int arr1[n], arr2[n];
    cout << "Enter " << n << " elements:\n";
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
        arr2[i] = arr1[i]; // Copy for second reverse
    }

    reverse1(0, n - 1, arr1);
    cout << "Reversed using reverse1 (two pointers): ";
    for (int i = 0; i < n; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;

    reverse2(0, n, arr2);
    cout << "Reversed using reverse2 (single pointer): ";
    for (int i = 0; i < n; i++) {
        cout << arr2[i] << " ";
    }

    return 0;
}
/***
 * 
 * 
 * 
 * Enter size of array: 5
Enter 5 elements:
1
2
3
4
5
Reversed using reverse1 (two pointers): 5 4 3 2 1 
Reversed using reverse2 (single pointer): 5 4 3 2 1
 */
// find unique element in an array
// ip : 2, 3, 4, 2, 3, 4, 5
// output : 5
#include <iostream>
using namespace std;

int findUnique(int arr[], int size) {
    int result = 0;

    for (int i = 0; i < size; i++) {
        result ^= arr[i];
    }

    return result;
}

int main() {
    int numbers[] = {2, 3, 4, 2, 3, 4, 5};

    int size = sizeof(numbers) / sizeof(numbers[0]);
    int uniqueElement = findUnique(numbers, size);

    cout << "Unique element: " << uniqueElement << endl;

    return 0;
}


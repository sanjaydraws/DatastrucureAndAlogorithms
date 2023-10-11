
//print all unique triplets of elements from an array in C++
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {1, 2, 3, 4, 5};

    cout << "Triplets in the array:" << endl;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            for (int k = j + 1; k < SIZE; k++) {
                cout << "(" << numbers[i] << ", " << numbers[j] << ", " << numbers[k] << ")" << endl;
            }
        }
    }

    return 0;
}

/*Output
Triplets in the array:
(1, 2, 3)
(1, 2, 4)
(1, 2, 5)
(1, 3, 4)
(1, 3, 5)
(1, 4, 5)
(2, 3, 4)
(2, 3, 5)
(2, 4, 5)
(3, 4, 5)

*/
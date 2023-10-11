// prints pair from an array
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 5;
    int numbers[SIZE] = {1, 2, 3, 4, 5};

    cout << "Pairs in the array:" << endl;

    for (int i = 0; i < SIZE; i++) {
        for (int j = i + 1; j < SIZE; j++) {
            cout << "(" << numbers[i] << ", " << numbers[j] << ")" << endl;
        }
    }

    return 0;
}
/*Output
Pairs in the array:
(1, 2)
(1, 3)
(1, 4)
(1, 5)
(2, 3)
(2, 4)
(2, 5)
(3, 4)
(3, 5)
(4, 5)

*/
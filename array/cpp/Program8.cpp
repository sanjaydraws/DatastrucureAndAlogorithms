// find uniques element in array
#include <iostream>
using namespace std;

int main() {
    const int SIZE = 10; 
    int numbers[SIZE] = {1, 2, 2, 3, 3, 4, 5, 6, 6, 7}; 

    cout << "Unique elements: ";

    for (int i = 0; i < SIZE; i++) {
        bool isUnique = true;

        for (int j = 0; j < i; j++) {
            if (numbers[i] == numbers[j]) {
                isUnique = false;
                break;
            }
        }

        if (isUnique) {
            cout << numbers[i] << " ";
        }
    }

    return 0;
}

//Output
//Unique elements: 1 2 3 4 5 6 7 
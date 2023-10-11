
// find maximum and minimum element in 2d array in cpp 
#include <iostream>
using namespace std;

const int ROWS = 3;
const int COLS = 4;

int findMaxElement(int arr[ROWS][COLS]) {
    int maxElement = arr[0][0];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(arr[i][j] > maxElement) {
                maxElement = arr[i][j];
            }
        }
    }

    return maxElement;
}
int findMinElement(int arr[ROWS][COLS]) {
    int minElement = arr[0][0];

    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(arr[i][j] < minElement) {
                minElement = arr[i][j];
            }
        }
    }

    return minElement;
}


int main() {
    int arr[ROWS][COLS] = {{1, 2, 3, 4},
                           {5, 6, 7, 8},
                           {9, 10, 11, 12}};

    int maxElement = findMaxElement(arr);

    cout << "The maximum element in the 2D array is: " << maxElement << endl;

     int minElement = findMinElement(arr);

    cout << "The minimum element in the 2D array is: " << minElement << endl;


    return 0;
}
/**Output
The maximum element in the 2D array is: 12
The minimum element in the 2D array is: 1
*/

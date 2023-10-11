// find element in 2d array in cpp 

#include <iostream>
using namespace std;

bool findElement(int arr[][3], int rows, int cols, int target) {
  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (arr[i][j] == target) {
        return true;
      }
    }
  }
  return false;
}

int main() {
  const int rows = 2;
  const int cols = 3;
  int myArray[rows][cols] = {{1, 2, 3}, {4, 5, 6}};
  int elementToFind = 3;

  if (findElement(myArray, rows, cols, elementToFind)) {
    cout << elementToFind << " is found in the array." << endl;
  } else {
    cout << elementToFind << " is not found in the array." << endl;
  }

  return 0;
}

/*Output
3 is found in the array.
**/


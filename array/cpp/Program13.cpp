// Print 2d array rowwise  and columnwise

#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void colWisePrint(int arr[][4], int row, int col) {
  for (int i = 0; i < col; i++) {
    for (int j = 0; j < row; j++) {
      cout << arr[j][i] << " ";
    }
    cout << endl;
  }
}

// print array row wise
void rowWisePrint(int arr[][4], int row, int col) {
  for (int i = 0; i < row; i++) {
    for (int j = 0; j < col; j++) {

      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {
  int arr[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 1, 11}};

  int row = 3;
  int col = 4;\
  cout<<"Print array elements rowwise"<<endl;
  rowWisePrint(arr, row, col);
  cout<<endl;
  cout<<"Print array elements column wise"<<endl;
  colWisePrint(arr, row, col);
  return 0;
}
//Output
/**
Print array elements rowwise
1 2 3 4 
5 6 7 8 
9 10 1 11 

Print array elements column wise
1 5 9 
2 6 10 
3 7 1 
4 8 11 
*/
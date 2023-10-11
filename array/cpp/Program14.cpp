// transpose 2d array 


#include <iostream>
#include <limits.h>
#include <vector>
using namespace std;

void transpose(int arr[][4], int row, int col ) {
  
  for(int i=0; i<row; i++) {
    
    for(int j=i; j<col; j++) {
      
      swap(arr[i][j], arr[j][i]);
      
    }
  }
}

void printArray(int arr[][4], int row, int col) {
  for(int i=0; i<row; i++ ) {
    for(int j=0; j<col; j++) {

      cout << arr[i][j] << " ";
    }
    cout << endl;
  }
}

int main() {

  int arr[4][4] = {
         {1,2,3,4},
         {5,6,70,8},
         {9,10,1,11},
         {12,24,46,89}
         };
  int row = 4;
  int col = 4;
  
  cout<< endl << "Printing before transpose" << endl;
  printArray(arr, row, col);

  cout<< endl  << "Doing transpose" << endl;
  transpose(arr, row,  col);

  cout<< endl  << "Printing after transpose" << endl;
  printArray(arr, row, col);
}
//Output
/**
Printing before transpose
1 2 3 4 
5 6 70 8 
9 10 1 11 
12 24 46 89 

Doing transpose

Printing after transpose
1 5 9 12 
2 6 10 24 
3 70 1 46 
4 8 11 89 
*/